#pragma once

#include "State.hpp"

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(State* state) = 0;
};