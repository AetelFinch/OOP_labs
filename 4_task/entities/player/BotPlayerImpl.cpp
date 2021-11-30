#include "BotPlayerImpl.h"

BotPlayerImpl::BotPlayerImpl(GameField *gameField, Chip chip) : PlayerInterface(gameField, chip) { }

int BotPlayerImpl::dropChip()
{
    auto seed = unsigned(std::time(nullptr));
    std::random_device rd;
    std::mt19937 mersenne(rd());
    mersenne.seed(seed);
    std::uniform_int_distribution<size_t> distribution(0, 7);


    unsigned int turn;
    int state = -1;

    while (state == -1)
    {
        turn = distribution(mersenne);
        state = _gameField->dropChip(turn, _chip);
    }
    return state;
}
