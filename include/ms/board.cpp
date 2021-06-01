#include "board.hpp"

namespace ms
{
    Board::Board(   std::shared_ptr<sf::RenderWindow> a_window,
                    sf::Vector2f a_tile_size,
                    sf::Vector2i a_tile_count,
                    uint32_t a_mine_count,
                    uint32_t a_random_seed )
        : Dynamic(  sf::Vector2f(   a_tile_size.x * a_tile_count.x,
                                    a_tile_size.y * a_tile_count.y  ),
                    sf::Vector2f(   (a_window->getSize().x - a_tile_size.x * a_tile_count.x) / 2,
                                    (a_window->getSize().y - a_tile_size.y * a_tile_count.y) / 2    ))
        , window(a_window)
        , tile_size(a_tile_size)
        , tile_count(a_tile_count)
        , mine_count(a_mine_count)
        , random_seed(a_random_seed)
    {
        // Load the font and set its size relative to the tile size.
        tile_font.loadFromFile(FONT_PATH);
        tile_font_size = std::min(tile_size.x, tile_size.y) * 0.7;

        board_size.x = tile_size.x * tile_count.x;
        board_size.y = tile_size.y * tile_count.y;

        // Position the board in the center of the window.
        sf::Vector2u window_size = window->getSize();
        board_position.x = (window_size.x - board_size.x) / 2;
        board_position.y = (window_size.y - board_size.y) / 2;
    }
    
    Board::~Board() 
    { }
    
    // Draw the board graphics.
    void Board::Draw() 
    {
        for (auto &collumns : tiles)
        {
            for (auto &rows : collumns)
            {
                rows->Draw();
            }
        }

        return;
    }
    
    // Create a board and add mines to it.
    void Board::Initialise() 
    {
        GenerateBoard();
        MapNearbyTiles();
        PlaceMines();
        UpdateNearbyMines();

        return;
    }
    
    // Create the array of tiles that make up the board.
    void Board::GenerateBoard() 
    {
        for (int i = 0; i < tile_count.x; i++)
        {
            std::vector<std::shared_ptr<Tile>> collumn;

            for (int j = 0; j < tile_count.y; j++)
            {
                std::shared_ptr<Tile> tile(new Tile(shared_from_this(), sf::Vector2i(i, j)));
                collumn.push_back(tile);
            }
            
            tiles.push_back(collumn);
        }

        return;
    }
    
    // Place mines based on the seed.
    void Board::PlaceMines() 
    {
        std::srand(random_seed);
        
        uint32_t placed_mines = 0;
        uint32_t collumn;
        uint32_t row;

        while (placed_mines < mine_count)
        {
            collumn = std::rand() % (tile_count.x);
            row = std::rand() % (tile_count.y);

            if (!tiles.at(collumn).at(row)->mine)
            {
                tiles.at(collumn).at(row)->mine = true;
                placed_mines++;
            }
        }

        return;
    }
    
    // Remove all mines from the tile array.
    void Board::RemoveMines() 
    {
        for (auto &collums : tiles)
        {
            for (auto &rows : collums)
            {
                rows->mine = false;
            }
        }

        return;
    }
    
    // Designate adjacent tiles for each tile in the array.
    void Board::MapNearbyTiles() 
    {
        for (auto &collumns : tiles)
        {
            for (auto &rows : collumns)
            {
                for (int i = rows->tile_index.x - 1; i < rows->tile_index.x + 2; i++)
                {
                    for (int j = rows->tile_index.y - 1; j < rows->tile_index.y + 2; j++)
                    {
                        if (    i >= 0 &&
                                j >= 0 &&
                                i < tile_count.x &&
                                j < tile_count.y    )
                        {
                            if (    !(i == rows->tile_index.x &&
                                    j == rows->tile_index.y)    )
                            {
                                rows->tiles_nearby.push_back(tiles.at(i).at(j));
                            }
                        }
                    }
                }
            }
        }

        return;
    }
    
    // Update the count of adjacent mines for each tile in the array.
    void Board::UpdateNearbyMines() 
    {
        for (auto &collumns : tiles)
        {
            for (auto &rows : collumns)
            {
                rows->UpdateNearbyMines();
            }
        }

        return;
    }
    
    // Set the mine distribution seed to a specific value.
    void Board::SetRandomSeed(uint32_t a_random_seed) 
    {
        random_seed = a_random_seed;

        return;
    }
    
    // Increment the seed by 1.
    void Board::NewRandomSeed() 
    {
        random_seed++;

        return;
    }
    
    // Map window coordinates to a tile in the array.
    // Returns: a pointer to the tile.
    std::shared_ptr<Tile> Board::CoordsToTile(uint32_t a_x, uint32_t a_y) 
    {
        sf::Vector2f relative_position( a_x - board_position.x,
                                        a_y - board_position.y  );

        sf::Vector2i index( relative_position.x / tile_size.x,
                            relative_position.y / tile_size.y   );

        return tiles.at(index.x).at(index.y);
    }
}