#ifndef __EVENTLOG_H__
#define __EVENTLOG_H__

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
#include "mouseaction.hpp"

namespace ms
{
    class EventLog
    {
        public:

            EventLog(std::shared_ptr<Board> a_board);
            ~EventLog();

            void InitialiseLogs();

            std::shared_ptr<sf::Clock> event_clock;
            MouseAction left_press{nullptr, nullptr, sf::Event::MouseButtonPressed};
            MouseAction left_release{nullptr, nullptr, sf::Event::MouseButtonPressed};
            MouseAction right_press{nullptr, nullptr, sf::Event::MouseButtonPressed};
            MouseAction right_release{nullptr, nullptr, sf::Event::MouseButtonPressed};

        private:
            std::shared_ptr<Board> board;
    };
}

#endif // __EVENTLOG_H__