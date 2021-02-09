#include "definitions.hpp"
#include "minesweeper.hpp"


namespace ms
{
    Tile::Tile( std::shared_ptr<Board> a_board,
                sf::Vector2i a_tile_index   ) :
                board(a_board),
                tile_index(a_tile_index)
    {
        tile_position.x = board->board_position.x + tile_index.x * board->tile_size.x;
        tile_position.y = board->board_position.y + tile_index.y * board->tile_size.y;

        tile_position_center.x = tile_position.x + board->tile_size.x / 2;
        tile_position_center.y = tile_position.y + board->tile_size.y / 2;
    }
    
    Tile::~Tile() 
    {
        
    }

    // Draw tile depending on its state.
    void Tile::Draw() 
    {
        DrawBase();

        if (mine)
        {
            DrawCover();
            DrawFlag();
        }
        else
        {
            DrawNumber();
        }

        return;
        

        switch (board->game_state)
        {
            case GameState::Start:
            {
                DrawCover();
                break;
            }
            case GameState::Ongoing:
            {
                if (revealed)
                {
                    DrawNumber();
                }
                else if (flagged)
                {
                    DrawCover();
                    DrawFlag();
                }
                else if (questioned)
                {
                    DrawCover();
                    DrawQuestion();
                }

                break;
            }
            case GameState::Lost:
            case GameState::Won:
            {
                if (revealed && !mine)
                {
                    DrawNumber();
                }
                else if (!revealed)
                {
                    DrawCover();
                }

                if (mine)
                {
                    DrawMine();
                }

                if (questioned)
                {
                    DrawQuestion();
                }
                else if (flagged)
                {
                    DrawFlag();
                }
                
                break;
            }
        }

        return;
    }
    
    // Mark a tile with a flag, question mark or nothing at all.
    // Called when a tile is right clicked.
    void Tile::Mark() 
    {
        if (flagged)
        {
            flagged = false;
            
            if (use_question_marks)
            {
                questioned = true;
            }
        }
        else if (questioned)
        {
            questioned = false;
        }
        else
        {
            flagged = true;
        }
        
        return;
    }
    
    // Reveal a tile to show whether or not it is a mine.
    // Called when a tile is left clicked or revealed due to nearby tile reveals.
    void Tile::Reveal() 
    {
        revealed = true;

        if (mine)
        {
            board->game_state = GameState::Lost;
        }

        if (mines_nearby == 0)
        {
            for (auto &nearby : tiles_nearby)
            {
                nearby->Reveal();
            }
        }
        else
        {
            for (auto &nearby : tiles_nearby)
            {
                if (nearby->mines_nearby == 0)
                {
                    nearby->Reveal();
                }
            }
        }

        return;
    }
    
    void Tile::UpdateNearbyMines() 
    {
        mines_nearby = 0;

        for (auto &nearby : tiles_nearby)
        {
            if (nearby->mine)
            {
                mines_nearby++;
            }
        }

        return;
    }
    
    void Tile::DrawBase() 
    {
        sf::RectangleShape base(board->tile_size);
        base.setFillColor(board->color_base);
        base.setOutlineColor(board->color_border);
        base.setOutlineThickness(- board->tile_border_thickness);
        base.setPosition(tile_position);
        board->window->draw(base);

        return;
    }
    
    void Tile::DrawCover() 
    {
        sf::RectangleShape cover(sf::Vector2f(  board->tile_size.x - 2 * board->tile_border_thickness,
                                                board->tile_size.y - 2 * board->tile_border_thickness   ));
        cover.setFillColor(board->color_cover);
        cover.setPosition(sf::Vector2f( tile_position.x + board->tile_border_thickness,
                                        tile_position.y + board->tile_border_thickness  ));
        board->window->draw(cover);

        return;
    }
    
    void Tile::DrawNumber()
    {
        sf::RectangleShape base(board->tile_size);
        base.setPosition(tile_position);
        sf::Text number(    std::to_string(mines_nearby), 
                            board->tile_font, 
                            board->tile_font_size   );
        number.setFillColor(board->color_numbers.at(mines_nearby));
        number.setStyle(sf::Text::Bold);
        CenterText(number, base);
        board->window->draw(number);

        return;
    }
    
    void Tile::DrawMine() 
    {
        float circle_radius = std::min(board->tile_size.x, board->tile_size.y) / 2 - 2 * board->tile_border_thickness;
        sf::CircleShape mine(circle_radius, 8);
        mine.setOrigin(circle_radius, circle_radius);
        mine.setPosition(tile_position_center);
        revealed ? mine.setFillColor(board->color_mine_clicked) : mine.setFillColor(board->color_mine);
        board->window->draw(mine);

        return;
    }
    
    void Tile::DrawFlag() 
    {
        float circle_radius = std::min(board->tile_size.x, board->tile_size.y) / 2.5 - 2 * board->tile_border_thickness;
        sf::CircleShape flag(circle_radius, 3);
        flag.setOrigin(circle_radius, circle_radius);
        flag.setPosition(tile_position_center);
        flag.rotate(30.f);
        flag.setFillColor(board->color_flag);
        board->window->draw(flag);

        return;
    }
    
    void Tile::DrawQuestion() 
    {
        sf::RectangleShape base(board->tile_size);
        base.setPosition(tile_position);
        sf::Text question(  "?", 
                            board->tile_font, 
                            board->tile_font_size   );
        question.setFillColor(board->color_question);
        question.setStyle(sf::Text::Bold);
        CenterText(question, base);
        board->window->draw(question);

        return;
    }
    
    void Tile::DrawCross() 
    {
        float cross_thickness = 5.f;
        float cross_width = std::min(board->tile_size.x, board->tile_size.y) / std::sqrt(2);
        sf::RectangleShape line(sf::Vector2f(std::min(board->tile_size.x, board->tile_size.y), cross_thickness));

        line.setOrigin( std::min(board->tile_size.x, board->tile_size.y) / 2,
                        cross_thickness / 2);
        line.setPosition(tile_position_center);
        line.rotate(45.f);
        line.setFillColor(board->color_cross);
        board->window->draw(line);
        line.rotate(90.f);
        board->window->draw(line);

        return;
    }

    void Tile::CenterText(  sf::Text& a_text, 
                            sf::RectangleShape& a_box) 
    {
        sf::FloatRect text_bounds = a_text.getLocalBounds();
        a_text.setOrigin( text_bounds.left + text_bounds.width / 2.f,
                            text_bounds.top + text_bounds.height / 2.f  );
        sf::Vector2f text_position = a_box.getPosition() + 0.5f * a_box.getSize();
        a_text.setPosition(text_position);

        return;
    }
    
    Board::Board(   std::shared_ptr<sf::RenderWindow> a_window,
                    sf::Vector2f a_tile_size,
                    sf::Vector2i a_tile_count,
                    uint32_t a_mine_count,
                    uint32_t a_random_seed ) :
                    window(a_window),
                    tile_size(a_tile_size),
                    tile_count(a_tile_count),
                    mine_count(a_mine_count),
                    random_seed(a_random_seed)
    {
        tile_font.loadFromFile(FONT_PATH);
        tile_font_size = std::min(tile_size.x, tile_size.y) * 0.7;

        board_size.x = tile_size.x * tile_count.x;
        board_size.y = tile_size.y * tile_count.y;

        sf::Vector2u window_size = window->getSize();
        board_position.x = (window_size.x - board_size.x) / 2;
        board_position.y = (window_size.y - board_size.y) / 2;
    }
    
    Board::~Board() 
    {
        
    }
    
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
    
    EventHandler::EventHandler( std::shared_ptr<sf::Event> a_event,
                                std::shared_ptr<EventLog> a_event_log,
                                std::shared_ptr<sf::RenderWindow> a_window,
                                std::shared_ptr<Board> a_board  ) :
                                event(a_event),
                                event_log(a_event_log),
                                window(a_window),
                                board(a_board)
    {
        switch (event->type)
        {
            case sf::Event::Closed:
            {
                window->close();
                break;
            }
        }
    }
    
    EventHandler::~EventHandler() 
    {
        
    }
    
    EventLog::EventLog( std::shared_ptr<Board> a_board) :
                        board(a_board)
    {
        
    }
    
    EventLog::~EventLog() 
    {
        
    }
    
    MouseAction::MouseAction() 
    {
        
    }
    
    MouseAction::~MouseAction() 
    {
        
    }
    
    void MouseAction::Log() 
    {
        
    }
}