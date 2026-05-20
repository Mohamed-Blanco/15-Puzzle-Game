
#include "Board.h"


std::ostream& operator <<(std::ostream& out, const Board& board) 
{
    for(int i{}; i < 4 ; ++i)
    {
        for(int j {}; j < 4 ; ++j)
        {
            std::cout << board.m_board[i][j]; 
        }
        std::cout << "\n"; 
    }

    return out; 
} 
