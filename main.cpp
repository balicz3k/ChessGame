#include <iostream>
#include "Game.hpp"

int main()
{
    auto game = Game::getInstance();
    game->play();
    return 0;
}