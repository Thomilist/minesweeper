#include "element.hpp"

namespace ui
{
    Element::Element(   sf::Vector2f a_size,
                        sf::Vector2f a_position,
                        std::shared_ptr<sf::RenderWindow> a_window  )
        : RectangleShape(a_size)
        , size(a_size)
        , position_1(a_position)
        , window(a_window)
    {
        center.x = position_1.x + size.x / 2;
        center.y = position_1.y + size.y / 2;

        position_2.x = position_1.x + size.x;
        position_2.y = position_1.y + size.y;

        setPosition(position_1);
    }
    
    Element::~Element() 
    { }
}