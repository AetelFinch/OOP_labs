#include "BotPlayerImpl.h"

BotPlayerImpl::BotPlayerImpl(GameField *gameField, Chip chip) : PlayerInterface(gameField, chip) { }

int BotPlayerImpl::dropChip()
{
    std::random_device rd;
    std::mt19937 mersenne(rd());

    unsigned int turn = mersenne() % _gameField->getWidth();
    return _gameField->dropChip(turn, _chip);
}
