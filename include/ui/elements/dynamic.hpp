#ifndef __DYNAMIC_H__
#define __DYNAMIC_H__

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
#include "element.hpp"

namespace ui
{
    class Dynamic : public Element
    {
        public:
            Dynamic(    sf::Vector2f a_size,
                        sf::Vector2f a_position,
                        std::shared_ptr<sf::RenderWindow> a_window  );
            ~Dynamic();

            bool IsPointWithin(sf::Vector2f a_point);
            bool IsMouseOver();
            void Enable();
            void Disable();

            bool enabled = true;    // Indicates if the element can currently be interacted with.
    };
}

#endif // __DYNAMIC_H__