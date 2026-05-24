
#include "Board.h"
#include "../Point/Point.h"
#include "../Direction/Direction.h"

std::ostream& operator <<(std::ostream& out, const Board& board) 
{
    for(int i{}; i < 4 ; ++i)
    {
        for(int j {}; j < 4 ; ++j)
        {
            std::cout << board.m_tiles[i][j]; 
        }
        std::cout << "\n"; 
    }

    return out; 
} 


void Board::moveTile(Direction::Type direction )
{
    //find the empty cell 
    Point point; 
    int i,j ; 
    for (int i{}; i < 4; ++i)
    {
        for (int j{}; j < 4; ++j)
        {
            if (m_tiles[i][j].isEmpty())
            {
                point = Point{j,i};                 
            }
        }
    }

    //getting the adjacent point for this point 
    Point adjPoint {point.getAdjacentPoint(direction)}; 

    //swapping the empty tile with the current Tile
    std::swap(m_tiles[point.getY()][point.getX()], m_tiles[adjPoint.getY()][adjPoint.getX()]);
    
    return ; 
}

bool Board::operator ==(const Board& board)
{
    for(int i{}; i < 4; ++i)
    {
        for(int j{}; j < 4; ++j)
        {
            if(m_tiles[i][j].getNum() != board.m_tiles[i][j].getNum())
            {
                return false; 
            }
        }
    }

    return true ; 
}

void Board::randomize()
{
    std::cout << "Generating Random Board to start the game !\n"; 
    for(int i{}; i < 1000; ++i)
    {
        moveTile(Direction::generateRandomDir().getDirectionType()); 
    }
    std::cout << "\n\nHere we go Start! \n";
}






