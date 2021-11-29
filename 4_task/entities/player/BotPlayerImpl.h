#ifndef INC_4_TO_LINE_BOTPLAYERIMPL_H
#define INC_4_TO_LINE_BOTPLAYERIMPL_H

#include <random>

#include "PlayerInterface.h"

class BotPlayerImpl : public PlayerInterface
{
public:
    BotPlayerImpl(GameField *gameField, Chip chip);
    int dropChip() override;
};


#endif //INC_4_TO_LINE_BOTPLAYERIMPL_H
