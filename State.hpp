#pragma once

#include <iostream>

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
    void handle() final { std::cout << "\n\t--- Chess Game ---\n"; }
};