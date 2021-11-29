#include "HumanPlayerImpl.h"

HumanPlayerImpl::HumanPlayerImpl(GameField *gameField, Chip chip) : PlayerInterface(gameField, chip) { }

int HumanPlayerImpl::dropChip()
{
    int turn;
    std::cin >> turn;
    return _gameField->dropChip(turn, _chip);
}
