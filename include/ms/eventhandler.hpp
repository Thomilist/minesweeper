#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

// Standard libraries
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <cmath>

// SFML modules
#include <SFML/Graphics.hpp>

// Custom headers
#include "definitions.hpp"
#include "enums.hpp"
#include "board.hpp"
#include "eventlog.hpp"

namespace ms
{
    class EventHandler
    {
        public:
            EventHandler(   std::shared_ptr<sf::Event> a_event,
                            std::shared_ptr<EventLog> a_event_log,
                            std::shared_ptr<sf::RenderWindow> a_window,
                            std::shared_ptr<Board> a_board  );
            ~EventHandler();

            void MousePress();
            void MouseRelease();

        private:
            std::shared_ptr<sf::Event> event;           // The most recent event.
            std::shared_ptr<EventLog> event_log;        // An object keeping track of events.
            std::shared_ptr<sf::RenderWindow> window;   // The window that graphics are drawn to.
            std::shared_ptr<Board> board;               // The board of the current Minesweeper game.
    };
}

#endif // __EVENTHANDLER_H__