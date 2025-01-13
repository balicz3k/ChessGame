#pragma once

#include <iostream>
#include "Board.hpp"

class State
{
public:
    virtual void handle() = 0;
    virtual ~State() {}
};

class WhiteWin : public State
{
public:
    void handle() final { std::cout << "White wins!" << std::endl; }
};

class BlackWin : public State
{
public:
    void handle() final { std::cout << "Black wins!" << std::endl; }
};

class Stalemate : public State
{
public:
    void handle() final { std::cout << "It's a stalemate!" << std::endl; }
};

class InGame : public State
{
public:
    void handle() final { std::cout << "Game is in progress." << std::endl; }
};

class Draw : public State
{
public:
    void handle() final { std::cout << "It's a draw!" << std::endl; }
};

class Game
{
    static Game* instance;
    State* state{nullptr};
    Game() = delete;
    Game(State* s) : state{s} {};

public:
    static Game* getInstance();
    ~Game() { delete state; }
    void setState(State* s);
    void handle() { state->handle(); }
    void play();
    bool keepPlaying();
};