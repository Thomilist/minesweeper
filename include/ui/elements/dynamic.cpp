#include "dynamic.hpp"

namespace ui
{
    Dynamic::Dynamic(   sf::Vector2f a_size,
                        sf::Vector2f a_position,
                        std::shared_ptr<sf::RenderWindow> a_window  ) 
        : Element(a_size, a_position, a_window)
    {
        
    }
    
    Dynamic::~Dynamic() 
    { }
    
    // Checks if the provided point is within the bounds of the element.
    bool Dynamic::IsPointWithin(sf::Vector2f a_point) 
    {
        return
            (a_point.x >= position_1.x) &&
            (a_point.y >= position_1.y) &&
            (a_point.x <= position_2.x) &&
            (a_point.y <= position_2.y);
    }
    
    // Checks if the mouse is over this element.
    bool Dynamic::IsMouseOver() 
    {
        sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);
        return IsPointWithin(sf::Vector2f(mouse_position));
    }
}