#include <iostream>
#include "Tile/Tile.h"
#include "Board/Board.h"

constexpr int g_consoleLines{ 25 };

int main()
{
    Board board{};
    std::cout << board;

    return 0;
}

