#include <iostream>
#include "Board.hpp"

bool keepAlive()
{
    char user_choice;
    std::cout << "Game ended. Press 'r' (and Enter) to restart or any other key to quit.\n\n";
    std::cin >> user_choice;
    if (user_choice == 'r')
    {
        return true;
    }
    return false;
}

int main()
{
    Board chessboard;
    bool is_draw{false};
    chessboard.startMessage();
    chessboard.printBoard();
    while (true)
    {
        chessboard.makeMove();
        chessboard.alternateTurn();
        if (chessboard.isCheckmate())
        {
            chessboard.printBoard();
            std::string winning_player;
            winning_player = (chessboard.getTurnColour() == 'W') ? "Black" : "White";
            chessboard.endMessageWin(winning_player);
            if (keepAlive())
            {
                main();
            };
            break;
        }
        else if (chessboard.isStalemate())
        {
            chessboard.printBoard();
            chessboard.endMessageDraw();
            if (keepAlive())
            {
                main();
            };
            break;
        }
        chessboard.printBoard();
    }
    return 0;
}