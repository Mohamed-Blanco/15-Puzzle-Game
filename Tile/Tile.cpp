
#include <iostream>
#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    if (tile.isEmpty())
    {
        out << "\t";
    }
    else
    {
        out  <<tile.m_value <<  "\t";
    }
    return out;
}


Tile& Tile::operator =(int value)
{
    m_value = value;
    return *this;  
}


