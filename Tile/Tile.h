#ifndef TILE_H 
#define TILE_H

#include <iostream>

class Tile
{
    public:
        explicit Tile(int value)
        :m_value{value}
        {

        }

        Tile() = default; 

        bool isEmpty() const
        {
            return m_value == 0; 
        }



        int getNum() const
        {
            return m_value; 
        }

        friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
        Tile& operator=(int value);  
        

    private:
        int m_x{}; 
        int m_y{}; 
        int m_value{}; 
}; 

#endif 