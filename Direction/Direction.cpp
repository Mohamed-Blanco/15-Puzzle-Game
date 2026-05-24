

#include <string>
#include <iostream>
#include "Direction.h"
#include "../Random/Random.h"
#include <cassert>

std::ostream &operator<<(std::ostream &out, const Direction &direction)
{
    out << direction.directionArrayStr[direction.m_direction] << "\n";
    return out;
}

Direction& Direction::operator-()
{

    switch (this->m_direction)
    {
    case up:
        this->m_direction = down;
        break ;
    case down: 
        this->m_direction = up;
        break;
    case left: 
        this->m_direction = right;
        break;
    case right:
        this->m_direction = left;
        break;
    default:
        break;
    }


    return *this;
}

Direction Direction::generateRandomDir()
{
    assert(std::size(Direction::directionArray) == Direction::max_direction); 
    Direction randDir{Direction::directionArray[Random::get(0, 3)]};
    return randDir;     
}
