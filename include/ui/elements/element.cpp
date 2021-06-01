#include "element.hpp"

namespace ui
{
    Element::Element(   sf::Vector2f a_size,
                        sf::Vector2f a_position   )
        : RectangleShape(a_size)
        , size(a_size)
        , position(a_position)
    {
        center.x = position.x + size.x / 2;
        center.y = position.y + size.y / 2;

        setPosition(position);
    }
    
    Element::~Element() 
    { }
}