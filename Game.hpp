#pragma once

#include <iostream>
#include "Board.hpp"
#include "Observer.hpp"
#include "State.hpp"

class Game : Observer
{
    static Game* instance;
    State* state{nullptr};
    Board* chessboard;
    Game() = delete;
    Game(State* s) : state{s}
    {
        chessboard = Board::getInstance();
        chessboard->attach(this);
    };
    void update(State* state) final;

public:
    static Game* getInstance();
    ~Game() { delete state; }
    void setState(State* s);
    void play();
    bool keepPlaying();
};