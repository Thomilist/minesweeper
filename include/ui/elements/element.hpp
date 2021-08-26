#ifndef __ELEMENT_H__
#define __ELEMENT_H__

// Standard libraries
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <cmath>

// SFML modules
#include <SFML/Graphics.hpp>

// Custom headers
#include "../../definitions.hpp"

namespace ui
{
    class Element : public sf::RectangleShape
    {
        public:
            Element(    sf::Vector2f a_size,
                        sf::Vector2f a_position,
                        std::shared_ptr<sf::RenderWindow> a_window  );
            ~Element();

            std::shared_ptr<sf::RenderWindow> window;
            sf::Vector2f size;
            sf::Vector2f position_1;                        // Top left corner.
            sf::Vector2f position_2;                        // Bottom right corner.
            sf::Vector2f center;

        private:

    };
}

#endif // __ELEMENT_H__