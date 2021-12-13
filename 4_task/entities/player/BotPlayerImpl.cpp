#include "BotPlayerImpl.h"

#include <chrono>
#include <random>
#include <windows.h>

BotPlayerImpl::BotPlayerImpl(GameField *gameField, Chip chip) : PlayerInterface(gameField, chip) { }

int BotPlayerImpl::dropChip()
{
    Sleep(500);
    int state = -1;

    int t = checkHorizontal(_gameField->getField());
    if (t != -1)
    {
        state = _gameField->dropChip(t, _chip);
        return state;
    }

    t = checkVertical(_gameField->getField());
    if (t != -1)
    {
        state = _gameField->dropChip(t, _chip);
        return state;
    }

    unsigned int turn;

    while (state == -1)
    {
        turn = getRandomColumnNumber();
        state = _gameField->dropChip((int)turn, _chip);
    }
    return state;
}

int BotPlayerImpl::checkHorizontal(const std::vector<std::vector<Chip>> &field)
{

    for (const auto& line : field)
    {
        int chipInLine = 0;
        int otherChipInLine = 0;
        for (int i = 0; i < _gameField->getWidth(); ++i)
        {
            if (chipInLine == 3 && line.at(i) == NONE)
            {
                return i;
            }
            if (otherChipInLine == 3 && line.at(i) == NONE)
            {
                return i;
            }

            if (line.at(i) != _chip)
            {
                chipInLine = 0;
            }
            else if (line.at(i) == _chip)
            {
                ++chipInLine;
            }

            if (line.at(i) == _chip || line.at(i) == NONE)
            {
                otherChipInLine = 0;
            }
            else if (line.at(i) != _chip && line.at(i) != NONE)
            {
                ++otherChipInLine;
            }
        }

        chipInLine = 0;
        otherChipInLine = 0;
        for (int i = _gameField->getWidth() - 1; i >= 0; --i)
        {
            if (chipInLine == 3 && line.at(i) == NONE)
            {
                return i;
            }
            if (otherChipInLine == 3 && line.at(i) == NONE)
            {
                return i;
            }

            if (line.at(i) != _chip)
            {
                chipInLine = 0;
            }
            else if (line.at(i) == _chip)
            {
                ++chipInLine;
            }

            if (line.at(i) == _chip || line.at(i) == NONE)
            {
                otherChipInLine = 0;
            }
            else if (line.at(i) != _chip && line.at(i) != NONE)
            {
                ++otherChipInLine;
            }
        }
    }
    return -1;
}

int BotPlayerImpl::checkVertical(const std::vector<std::vector<Chip>> &field)
{
    for (int j = 0; j < _gameField->getWidth(); ++j)
    {
        int chipInLine = 0;
        int otherChipInLine = 0;
        for (int i = 0; i < _gameField->getHeight(); ++i)
        {
            if (chipInLine == 3 && field.at(i).at(j) == NONE)
            {
                return j;
            }
            if (otherChipInLine == 3 && field.at(i).at(j) == NONE)
            {
                return j;
            }

            if (field.at(i).at(j) != _chip)
            {
                chipInLine = 0;
            }
            else if (field.at(i).at(j) == _chip)
            {
                ++chipInLine;
            }

            if (field.at(i).at(j) == _chip || field.at(i).at(j) == NONE)
            {
                otherChipInLine = 0;
            }
            else if (field.at(i).at(j) != _chip && field.at(i).at(j) != NONE)
            {
                ++otherChipInLine;
            }
        }
    }
    return -1;
}

unsigned int BotPlayerImpl::getRandomColumnNumber()
{
    auto seed = unsigned(std::rand());
    std::random_device rd;
    std::mt19937 mersenne(rd());
    mersenne.seed(seed);
    std::uniform_int_distribution<size_t> distribution(0, 7);

    return distribution(mersenne);
}
