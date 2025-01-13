#include "Game.hpp"

Game* Game::instance{nullptr};

Game* Game::getInstance()
{
    if (!instance)
    {
        instance = new Game(new InGame());
    }
    return instance;
}

void Game::setState(State* s)
{
    delete state;
    state = s;
}

void Game::play()
{
    Board chessboard = *Board::getInstance();
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
            if (keepPlaying())
            {
                play();
            };
            break;
        }
        else if (chessboard.isStalemate())
        {
            chessboard.printBoard();
            chessboard.endMessageDraw();
            if (keepPlaying())
            {
                play();
            };
            break;
        }
        chessboard.printBoard();
    }
}

bool Game::keepPlaying()
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