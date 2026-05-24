

#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "../Tile/Tile.h"
#include "../Random/Random.h"
#include "../Direction/Direction.h"

class Board
{
    public:
        Board()
        {
            int value {}; 
            for(int i {}; i < 4 ; ++i)
            {
                for(int j {}; j < 4; ++j)
                {
                    ++value; 
                    m_tiles[i][j] = value; 
                }
            }
            
            m_tiles[3][3] =  0; //last tile needs to be empty ; 
        }

        friend std::ostream& operator <<(std::ostream& out, const Board& board) ;
        bool operator ==(const Board& board ); 
        void moveTile(Direction::Type direction); 
        void randomize();
        
    private:
        std::array<std::array<Tile,4>,4> m_tiles {};

}; 

#endif