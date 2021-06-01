#include "dynamic.hpp"

namespace ui
{
    Dynamic::Dynamic(   sf::Vector2f a_size,
                        sf::Vector2f a_position   ) 
        : Element(a_size, a_position)
    {
        
    }
    
    Dynamic::~Dynamic() 
    { }
    
    // Checks if the provided point is within the bounds of the element.
    bool Dynamic::IsPointWithin(sf::Vector2f a_point) 
    {
        if (    (position.x < a_point.x) &&
                (a_point.x < position.x + size.x) &&
                (position.y < a_point.y) &&
                (a_point.y < position.y + size.y)   )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}