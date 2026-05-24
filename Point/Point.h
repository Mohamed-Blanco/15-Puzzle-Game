

#ifndef POINT_H 
#define POINT_H

#include <iostream>
#include "../Direction/Direction.h"

class Point
{
    
    public:
        Point() = default; 
        Point(int x, int y)
        :m_x{x},m_y{y}
        {

        }

        Point getAdjacentPoint(const Direction::Type); 
        friend std::ostream& operator<<(std::ostream& out, const Point& point);
        bool operator ==(const Point& point); 
        bool operator !=(const Point& point); 
        int getX()
        {
            return m_x ; 
        }
        int getY()
        {
            return m_y ; 
        }
    private:
        int m_x {}; 
        int m_y {}; 

}; 

#endif