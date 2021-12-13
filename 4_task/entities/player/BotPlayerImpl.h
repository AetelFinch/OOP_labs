#ifndef INC_4_TO_LINE_BOTPLAYERIMPL_H
#define INC_4_TO_LINE_BOTPLAYERIMPL_H

#include <random>
#include <ctime>

#include "PlayerInterface.h"

class BotPlayerImpl : public PlayerInterface
{
public:
    BotPlayerImpl(GameField *gameField, Chip chip);
    int dropChip() override;

private:
    int checkHorizontal(const std::vector<std::vector<Chip>>& field);
    int checkVertical(const std::vector<std::vector<Chip>>& field);
    unsigned int getRandomColumnNumber();
};


#endif //INC_4_TO_LINE_BOTPLAYERIMPL_H
