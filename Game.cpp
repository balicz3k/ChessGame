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
    bool is_draw{false};
    state->handle();
    chessboard->printBoard();
    while (true)
    {
        chessboard->makeMove();
        chessboard->alternateTurn();
        chessboard->printBoard();
        if (chessboard->isCheckmate())
        {
            state->handle();
            if (keepPlaying())
            {
                play();
            };
            break;
        }
        else if (chessboard->isStalemate())
        {
            state->handle();
            if (keepPlaying())
            {
                play();
            };
            break;
        }
        chessboard->printBoard();
    }
}

bool Game::keepPlaying()
{
    char user_choice;
    std::cout << "Game ended. Press 'r' (and Enter) to restart or any other key to quit.\n\n";
    std::cin >> user_choice;
    if (user_choice == 'r')
    {
        setState(new InGame());
        return true;
    }
    return false;
}

void Game::update(State* state)
{
    delete this->state;
    this->state = state;
}