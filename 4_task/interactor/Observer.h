#ifndef INC_4_TO_LINE_OBSERVER_H
#define INC_4_TO_LINE_OBSERVER_H

#include "../entities/GameState.h"

class Observer
{
public:
    virtual void update(GameState state) = 0;
};

#endif //INC_4_TO_LINE_OBSERVER_H
