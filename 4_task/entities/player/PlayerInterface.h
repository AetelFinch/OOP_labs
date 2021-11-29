#ifndef INC_4_TO_LINE_PLAYERINTERFACE_H
#define INC_4_TO_LINE_PLAYERINTERFACE_H

#include "../gamefield/GameField.h"

class PlayerInterface
{
public:
    PlayerInterface(GameField *gameField, Chip chip) : _gameField(gameField), _chip(chip) { }
    virtual int dropChip() = 0;

protected:
    GameField *_gameField;
    Chip _chip;
};

#endif //INC_4_TO_LINE_PLAYERINTERFACE_H
