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
    class MouseAction
    {
        public:
            MouseAction(    std::shared_ptr<Board> a_board,
                            std::shared_ptr<sf::Clock> a_event_clock,
                            sf::Event::EventType a_event_type   );
            ~MouseAction();

            bool Log(   std::shared_ptr<sf::Event> a_event  );

            sf::Time time_last = sf::milliseconds(-1);
            //sf::Vector2i tile_coords_last = sf::Vector2i(-1, -1);
            std::shared_ptr<Tile> tile_last;
        
        private:
            std::shared_ptr<sf::Clock> event_clock;
            std::shared_ptr<Board> board;
            sf::Event::EventType event_type;
    };
}

#endif // __MOUSEACTION_H__