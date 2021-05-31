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
        // The EventHandler object is re-initialised for every event.
        switch (event->type)
        {
            // The window is asked to close.
            case sf::Event::Closed:
            {
                window->close();
                break;
            }
            // The window receives a mouse button press.
            case sf::Event::MouseButtonPressed:
            {
                MousePress();
                break;
            }
            // The window receives a mouse button release.
            case sf::Event::MouseButtonReleased:
            {
                MouseRelease();
                break;
            }
        }
    }
    
    EventHandler::~EventHandler() 
    { }
    
    // Called whenever the left or right mouse button is pressed down.
    void EventHandler::MousePress() 
    {
        // The mouse position is mapped to a tile.
        std::shared_ptr<Tile> pressed_tile = board->CoordsToTile(event->mouseButton.x, event->mouseButton.y);
        
        // Case for left clicks.
        if (event->mouseButton.button == sf::Mouse::Button::Left)
        {
            // The game is in its initial state. The player clicks on a tile.
            if (board->game_state == GameState::Start)
            {
                // The game must start with an opening, so the board is remade with a new random seed until that rule is satisfied.
                while (pressed_tile->mine || pressed_tile->mines_nearby != 0)
                {
                    std::cout << "pressed_tile->mine " << pressed_tile->mine << "   pressed_tile->mines_nearby " << pressed_tile->mines_nearby << std::endl;
                    
                    board->RemoveMines();
                    board->NewRandomSeed();
                    board->PlaceMines();
                    board->UpdateNearbyMines();
                }
                
                // The game has now started, and the game state is updated.
                board->game_state = GameState::Ongoing;
            }
            
            // Handle clicks on revealed tiles.
            if (pressed_tile->revealed)
            {
                // A double click on the same tile can be used to clear an area where all nearby mines are flagged.
                if (    pressed_tile->tile_index == event_log->left_press.tile_last->tile_index &&
                        (event_log->event_clock->getElapsedTime() - event_log->left_press.time_last).asMilliseconds() < DOUBLE_CLICK_TIMEOUT    )
                {
                    pressed_tile->RevealSurrounding();
                }
            }
            
            // Update the event log.
            event_log->left_press.Log(event);
        }
        // Case for right clicks.
        else if (event->mouseButton.button == sf::Mouse::Button::Right)
        {
            // Covered tiles are flagged or question marked.
            if (!pressed_tile->revealed)
            {
                pressed_tile->Mark();
            }

            // Update the event log.
            event_log->right_press.Log(event);
        }
        
        return;
    }
    
    // Called whenever the left or right mouse button is released.
    void EventHandler::MouseRelease() 
    {
        // The mouse position is mapped to a tile.
        std::shared_ptr<Tile> released_tile = board->CoordsToTile(event->mouseButton.x, event->mouseButton.y);
        
        // Left clicking on a covered tile reveals the covered tile where the left mouse button is released.
        if (    !released_tile->revealed &&                                                 // The mouse button is released on a covered tile.
                !event_log->left_press.tile_last->revealed &&                               // The left mouse button was pressed down on a covered tile.
                event_log->left_press.time_last > event_log->right_release.time_last &&     // The right mouse button was released before pressing down the left.
                !sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) &&                    // The right mouse button is not pressed down.
                event->mouseButton.button == sf::Mouse::Button::Left    )                   // The mouse button being released is the left one.
        {
            released_tile->Reveal();
        }
        // Clicking with both mouse buttons (chording) on a revealed tile can be used to clear an area where all nearby mines are flagged.
        else if (   released_tile->revealed &&
                    event_log->left_press.time_last > event_log->left_release.time_last &&
                    event_log->right_press.time_last > event_log->right_release.time_last   )
        {
            released_tile->RevealSurrounding();
        }

        // Update the event log.
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