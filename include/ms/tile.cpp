#include "tile.hpp"

namespace ms
{
    Tile::Tile( std::shared_ptr<Board> a_board,
                sf::Vector2i a_tile_index   )
        : board(a_board)
        , tile_index(a_tile_index)
    {
        tile_position.x = board->board_position.x + tile_index.x * board->tile_size.x;
        tile_position.y = board->board_position.y + tile_index.y * board->tile_size.y;

        tile_position_center.x = tile_position.x + board->tile_size.x / 2;
        tile_position_center.y = tile_position.y + board->tile_size.y / 2;
    }
    
    Tile::~Tile() 
    { }

    // Draw tile depending on its state.
    void Tile::Draw() 
    {
        DrawBase();

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
                else
                {
                    DrawCover();

                    if (flagged)
                    {
                        DrawFlag();
                    }
                    else if (questioned)
                    {
                        DrawQuestion();
                    }
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

                if (questioned && !revealed)
                {
                    DrawQuestion();
                }
                else if (flagged && mine)
                {
                    DrawFlag();
                }
                else if (flagged && !mine)
                {
                    DrawCross();
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
            RemoveFlag();
            
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
            PlaceFlag();
        }
        
        return;
    }
    
    // Reveal a tile to show whether or not it is a mine.
    // Called when a tile is left clicked or revealed due to nearby tile reveals.
    void Tile::Reveal() 
    {
        if (revealed || flagged)
        {
            return;
        }
        
        revealed = true;

        if (mine)
        {
            board->game_state = GameState::Lost;
        }
        else if (mines_nearby == 0)
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
                if (nearby->mines_nearby == 0 && !nearby->mine)
                {
                    nearby->Reveal();
                }
            }
        }

        return;
    }
    
    // Function used for chording.
    void Tile::RevealSurrounding() 
    {
        if (mines_nearby == flags_nearby)
        {
            for (auto &nearby : tiles_nearby)
            {
                nearby->Reveal();
            }
        }

        return;
    }
    
    // Count the number of mines in the eight tiles surrounding this one and update the count.
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
    
    // Draw the background of a cleared tile.
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
    
    // Draw the top-most layer (except for markers) of a covered tile.
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
    
    // Draw the number on a cleared tile depending on the amount of nearby mines.
    // The number zero is not drawn visibly.
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
    
    // Draw a mine with colour depending on whether or not the tile was revealed.
    // Only used at the end of a game.
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
    
    // Draw a flag marker.
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
    
    // Draw a question mark.
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
    
    // Draw a cross.
    // Indicates an incorrectly placed flag after the game is finished.
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
    
    // Function to use when a tile is flagged to ensure proper updating of relevant counts.
    void Tile::PlaceFlag() 
    {
        flagged = true;

        for (auto &nearby : tiles_nearby)
        {
            nearby->flags_nearby++;
        }

        board->flag_count++;

        return;
    }
    
    // Function to use when a tile is unflagged to ensure proper updating of relevant counts.
    void Tile::RemoveFlag() 
    {
        flagged = false;

        for (auto &nearby : tiles_nearby)
        {
            nearby->flags_nearby--;
        }

        board->flag_count--;

        return;
    }

    // Position a text field in the center of a rectangle.
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
}