

#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "../Tile/Tile.h"
#include "../Random/Random.h"

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
                    m_board[i][j] = value; 
                }
            }
            
            m_board[3][3] =  0; //last tile needs to be empty ; 
        }

        friend std::ostream& operator <<(std::ostream& out, const Board& board) ;
    private:
        std::array<std::array<Tile,4>,4> m_board {};
        

}; 

#endif