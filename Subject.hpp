#pragma once

#include <algorithm>
#include <vector>
#include "Observer.hpp"

class Subject
{
private:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() = default;

    void attach(Observer* observer) { observers.push_back(observer); }

    void detach(Observer* observer)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(State* state)
    {
        for (Observer* observer : observers)
        {
            observer->update(state);
        }
    }
};