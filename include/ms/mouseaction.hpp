#ifndef __MOUSEACTION_H__
#define __MOUSEACTION_H__

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

namespace ms
{
    // A class to store information about mouse presses and releases.
    class MouseAction
    {
        public:
            MouseAction(    std::shared_ptr<Board> a_board,
                            std::shared_ptr<sf::Clock> a_event_clock,
                            sf::Event::EventType a_event_type   );
            ~MouseAction();

            bool Log(   std::shared_ptr<sf::Event> a_event  );

            sf::Time time_last = sf::milliseconds(-1);      // Timestamp of the previous instance of this event type.
            std::shared_ptr<Tile> tile_last;                // The tile that the previous event of this type interacted with.
        
        private:
            std::shared_ptr<sf::Clock> event_clock;         // The clock to use for event timestamps.
            std::shared_ptr<Board> board;                   // The Minesweeper board in use.
            sf::Event::EventType event_type;                // The type of event tracked.
    };
}

#endif // __MOUSEACTION_H__