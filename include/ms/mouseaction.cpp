#include "mouseaction.hpp"

namespace ms
{
    MouseAction::MouseAction(   std::shared_ptr<Board> a_board,
                                std::shared_ptr<sf::Clock> a_event_clock,
                                sf::Event::EventType a_event_type   )
        : board(a_board)
        , event_clock(a_event_clock)
        , event_type(a_event_type)
    { }
    
    MouseAction::~MouseAction() 
    { }
    
    // Log a new event if the type matches the tracked type.
    // Returns: true if the type matches, false otherwise.
    bool MouseAction::Log(  std::shared_ptr<sf::Event> a_event  ) 
    {
        if (a_event->type == event_type)
        {
            time_last = event_clock->getElapsedTime();
            tile_last = board->CoordsToTile(a_event->mouseButton.x, a_event->mouseButton.y);

            return true;
        }
        else
        {
            return false;
        }
    }
}