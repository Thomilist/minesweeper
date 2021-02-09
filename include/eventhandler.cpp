#include "eventhandler.hpp"

namespace ms
{
    EventHandler::EventHandler( std::shared_ptr<sf::Event> a_event,
                                std::shared_ptr<EventLog> a_event_log,
                                std::shared_ptr<sf::RenderWindow> a_window,
                                std::shared_ptr<Board> a_board  )
        : event(a_event)
        , event_log(a_event_log)
        , window(a_window)
        , board(a_board)
    {
        switch (event->type)
        {
            case sf::Event::Closed:
            {
                window->close();
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                MousePress();
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                MouseRelease();
                break;
            }
        }
    }
    
    EventHandler::~EventHandler() 
    { }
    
    void EventHandler::MousePress() 
    {
        std::shared_ptr<Tile> pressed_tile = board->CoordsToTile(event->mouseButton.x, event->mouseButton.y);
        
        if (event->mouseButton.button == sf::Mouse::Button::Left)
        {
            if (board->game_state == GameState::Start)
            {

                while (pressed_tile->mine || pressed_tile->mines_nearby != 0)
                {
                    std::cout << "pressed_tile->mine " << pressed_tile->mine << "   pressed_tile->mines_nearby " << pressed_tile->mines_nearby << std::endl;
                    
                    board->RemoveMines();
                    board->ChangeRandomSeed();
                    board->PlaceMines();
                    board->UpdateNearbyMines();
                }
                
                board->game_state = GameState::Ongoing;
            }
            
            if (pressed_tile->revealed)
            {
                if (    pressed_tile->tile_index == event_log->left_press.tile_last->tile_index &&
                        (event_log->event_clock->getElapsedTime() - event_log->left_press.time_last).asMilliseconds() < DOUBLE_CLICK_TIMEOUT    )
                {
                    pressed_tile->RevealSurrounding();
                }
            }
            
            event_log->left_press.Log(event);
        }
        else if (event->mouseButton.button == sf::Mouse::Button::Right)
        {
            if (!pressed_tile->revealed)
            {
                pressed_tile->Mark();
            }

            event_log->right_press.Log(event);
        }
        
        return;
    }
    
    void EventHandler::MouseRelease() 
    {
        std::shared_ptr<Tile> released_tile = board->CoordsToTile(event->mouseButton.x, event->mouseButton.y);
        
        if (    !released_tile->revealed &&
                !event_log->left_press.tile_last->revealed &&
                event_log->left_press.time_last > event_log->right_release.time_last &&
                !sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) &&
                event->mouseButton.button == sf::Mouse::Button::Left    )
        {
            released_tile->Reveal();
        }
        else if (   released_tile->revealed &&
                    event_log->left_press.time_last > event_log->left_release.time_last &&
                    event_log->right_press.time_last > event_log->right_release.time_last   )
        {
            released_tile->RevealSurrounding();
        }

        if (event->mouseButton.button == sf::Mouse::Button::Left)
        {
            event_log->left_release.Log(event);
        }
        else if (event->mouseButton.button == sf::Mouse::Button::Right)
        {
            event_log->right_release.Log(event);
        }
        
        return;
    }
}