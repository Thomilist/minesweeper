#include "eventlog.hpp"

namespace ms
{
    EventLog::EventLog( std::shared_ptr<Board> a_board  )
        : board(a_board)
    { }
    
    EventLog::~EventLog() 
    { }
    
    // The part of the initialisation that cannot happen in the constructor happens here.
    void EventLog::InitialiseLogs() 
    {
        event_clock = std::make_shared<sf::Clock>();
        
        left_press = MouseAction(board, event_clock, sf::Event::MouseButtonPressed);
        left_release = MouseAction(board, event_clock, sf::Event::MouseButtonReleased);
        right_press = MouseAction(board, event_clock, sf::Event::MouseButtonPressed);
        right_release = MouseAction(board, event_clock, sf::Event::MouseButtonReleased);

        return;
    }
}