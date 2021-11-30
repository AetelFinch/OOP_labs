#ifndef INC_4_TO_LINE_OBSERVABLE_H
#define INC_4_TO_LINE_OBSERVABLE_H

#include <vector>

#include "Observer.h"

class Observable
{
public:
    void registerObserver(Observer *observer)
    {
        _observers.push_back(observer);
    }

    void notifyObservers(GameState state)
    {
        for (auto observer : _observers)
        {
            observer->update(state);
        }
    }

protected:
    std::vector<Observer*> _observers;
};

#endif //INC_4_TO_LINE_OBSERVABLE_H
