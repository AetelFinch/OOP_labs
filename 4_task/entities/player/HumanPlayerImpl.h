#ifndef INC_4_TO_LINE_HUMANPLAYERIMPL_H
#define INC_4_TO_LINE_HUMANPLAYERIMPL_H

#include <iostream>

#include "PlayerInterface.h"

class HumanPlayerImpl : public PlayerInterface
{
public:
    HumanPlayerImpl(GameField *gameField, Chip chip);
    int dropChip() override;
};


#endif //INC_4_TO_LINE_HUMANPLAYERIMPL_H
