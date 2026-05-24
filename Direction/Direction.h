

#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>
#include <string>
#include <array>

class Direction
{

public:
    enum Type
    {
        up,
        down,
        left,
        right,
        max_direction
    }; 

    explicit Direction(Type dir) : m_direction{dir} {};
    static Direction generateRandomDir();
    friend std::ostream &operator<<(std::ostream &out, const Direction &direction);
    Direction& operator-(); 
    Type getDirectionType()
    {
        return m_direction; 
    }

private:
    Type m_direction{};
    inline static const std::array<std::string, 4> directionArrayStr{ "up", "down",  "left" ,"right" };
    inline static const std::array<Type, 4> directionArray{ up,down,left, right };

};

#endif