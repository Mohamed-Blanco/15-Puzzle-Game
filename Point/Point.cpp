

#include <iostream>
#include "Point.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out,const Point& point)
{
    out << "X = " << point.m_x << "Y = " << point.m_y ;
    return out ; 
}

bool Point::operator ==(const Point& point)
{
    return m_x == point.m_x && m_y == point.m_y; 
}


bool Point::operator !=(const Point& point )
{
    return !(*this == point) ; 
}

Point Point::getAdjacentPoint(const Direction::Type direction)
{
    assert(m_x >= 0 && m_x < 4 && m_y >= 0 && m_x < 4); 
    switch (direction)
    {
    case Direction::right:
        if(m_x < 3)
        {
            return Point(m_x + 1, m_y);
        }
        break;

    case Direction::left:
        if(m_x > 0  )
        {
            return Point(m_x - 1, m_y);
        }
        break;

    case Direction::down:
        if (m_y < 3)
        {
            return Point(m_x, m_y+1);
        }
        break ; 
    case Direction::up:
        if (m_y > 0)
        {
            return Point(m_x, m_y - 1);
        }
        break;

    default:
        return *this;
    }

    return *this;

}