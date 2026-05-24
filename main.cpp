#include <iostream>
#include "Tile/Tile.h"
#include "Board/Board.h"
#include "Direction/Direction.h"
#include "Point/Point.h"
#include <optional>

constexpr int g_consoleLines{25};

namespace UserInput
{

    Direction getDirection(const char input)
    {
        switch (input)
        {
        case 'z':
            return Direction{Direction::up};
        case 's':
            return Direction{ Direction::down};
        case 'a':
            return Direction{ Direction::left};
        case 'd':
            return Direction{ Direction::right};
        default:
            break;
        }
    }



    void generateRandom4directions()
    {
        for(int i{}; i < 4; ++i)
        {
            std::cout << "Generating random direction... " << Direction::generateRandomDir() <<"\n"; 
        }
        return ; 
    }


    std::optional<char> getUserInput()
    {

        while (true)
        {
            char input;
            std::cout << "\nEnter Command: ";

            std::cin >> input;
            if (input != 'z' && input != 's' && input != 'a' && input != 'd' && input != 'q')
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid Entry !!\n"; // Discards up to 1000 characters until a newline
                continue;
            }

            if (input == 'q')
            {
                std::cout << "\n\nBye!\n\n";
                return std::nullopt; 
            }
            else
            {
                std::cout << "You entered direction: " << UserInput::getDirection(input) << "\n";
            }

            return input;
        }
        
    }   
    
};



int main()
{
    Board board{};
    Board solvedBoard{}; 

    board.randomize();     
    std::cout << board; 

    while (!(board == solvedBoard))
    {
        auto input{ UserInput::getUserInput() };
        if(!input.has_value()) // if the user hit "q"
        {
            break; 
        }

        char userInput{input.value()}; 
        board.moveTile(UserInput::getDirection(userInput).getDirectionType());
    }

    std::cout << "\n\nYou won!\n\n";

    
    return 0;

}



