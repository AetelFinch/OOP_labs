#include "Arbiter.h"

Arbiter::Arbiter(Chip firstPlayerChip, Chip secondPlayerChip, GameField *field)
{
    _firstPlayerChip = firstPlayerChip;
    _secondPlayerChip = secondPlayerChip;
    _gameField = field;
}

GameState Arbiter::getGameState()
{
    std::vector<std::vector<Chip>> field = _gameField->getField();
    GameState state;

    state = checkHorizontal(field);
    if (state != CONTINUES)
        return state;

    state = checkVertical(field);
    if (state != CONTINUES)
        return state;

    state = checkRightDiagonal(field);
    if (state != CONTINUES)
        return state;

    state = checkLeftDiagonal(field);
    if (state != CONTINUES)
        return state;

    if (isDraw(field))
        return DRAW;

    return CONTINUES;
}

bool Arbiter::isDraw(std::vector<std::vector<Chip>> field)
{
    int height = _gameField->getHeight();

    for (int i = 0; i < _gameField->getWidth(); ++i)
    {
        if (field.at(height - 1).at(i) == NONE)
            return false;
    }
    return true;
}

GameState Arbiter::checkHorizontal(const std::vector<std::vector<Chip>>& field)
{
    for (const auto& line : field)
    {
        int numFirstPlayerChipInLine = 0;
        for (Chip chip : line)
        {
            if (chip == _firstPlayerChip)
                ++numFirstPlayerChipInLine;
            else
                numFirstPlayerChipInLine = 0;

            if (numFirstPlayerChipInLine == 4)
                return WIN;
        }

        int numSecondPlayerChipInLine = 0;
        for (Chip chip : line)
        {
            if (chip == _secondPlayerChip)
                ++numSecondPlayerChipInLine;
            else
                numSecondPlayerChipInLine = 0;

            if (numSecondPlayerChipInLine == 4)
                return LOSE;
        }
    }
    return CONTINUES;
}

GameState Arbiter::checkVertical(const std::vector<std::vector<Chip>>& field)
{
    for (int i = 0; i < _gameField->getWidth(); ++i)
    {
        int numFirstPlayerChipInLine = 0;
        for (int j = 0; j < _gameField->getHeight(); ++j)
        {
            Chip chip = field.at(j).at(i);
            if (chip == _firstPlayerChip)
                ++numFirstPlayerChipInLine;
            else
                numFirstPlayerChipInLine = 0;

            if (numFirstPlayerChipInLine == 4)
                return WIN;
        }

        int numSecondPlayerChipInLine = 0;
        for (int j = 0; j < _gameField->getHeight(); ++j)
        {
            Chip chip = field.at(j).at(i);
            if (chip == _secondPlayerChip)
                ++numSecondPlayerChipInLine;
            else
                numSecondPlayerChipInLine = 0;

            if (numSecondPlayerChipInLine == 4)
                return LOSE;
        }
    }
    return CONTINUES;
}

GameState Arbiter::checkLeftDiagonal(const std::vector<std::vector<Chip>>& field)
{
    int height = _gameField->getHeight();
    int width = _gameField->getWidth();

    for (int n = 0; n < width; ++n)
    {
        int numFirstPlayerChipInLine = 0;
        for (int i = 0; i < height && n - i >= 0; ++i)
        {
            Chip chip = field.at(i).at(n - i);
            if (chip == _firstPlayerChip)
                ++numFirstPlayerChipInLine;
            else
                numFirstPlayerChipInLine = 0;

            if (numFirstPlayerChipInLine == 4)
                return WIN;
        }

        int numSecondPlayerChipInLine = 0;
        for (int i = 0; i < height && n - i >= 0; ++i)
        {
            Chip chip = field.at(i).at(n - i);
            if (chip == _secondPlayerChip)
                ++numSecondPlayerChipInLine;
            else
                numSecondPlayerChipInLine = 0;

            if (numSecondPlayerChipInLine == 4)
                return LOSE;
        }
    }

    for (int n = height - 1; n >= 0; --n)
    {
        int numFirstPlayerChipInLine = 0;
        for (int i = width - 1; i >= 0 && width - 1 - i + n < height ; --i)
        {
            Chip chip = field.at(width - 1 - i + n).at(i);
            if (chip == _firstPlayerChip)
                ++numFirstPlayerChipInLine;
            else
                numFirstPlayerChipInLine = 0;

            if (numFirstPlayerChipInLine == 4)
                return WIN;
        }

        int numSecondPlayerChipInLine = 0;
        for (int i = width - 1; i >= 0 && width - 1 - i + n < height ; --i)
        {
            Chip chip = field.at(width - 1 - i + n).at(i);
            if (chip == _secondPlayerChip)
                ++numSecondPlayerChipInLine;
            else
                numSecondPlayerChipInLine = 0;

            if (numSecondPlayerChipInLine == 4)
                return LOSE;
        }
    }
    return CONTINUES;
}

GameState Arbiter::checkRightDiagonal(const std::vector<std::vector<Chip>> &field)
{
    int height = _gameField->getHeight();
    int width = _gameField->getWidth();

    for (int n = height - 1; n >= 0; --n)
    {
        int numFirstPlayerChipInLine = 0;
        for (int i = 0; i < width && n + i < height; ++i)
        {
            Chip chip = field.at(n + i).at(i);
            if (chip == _firstPlayerChip)
                ++numFirstPlayerChipInLine;
            else
                numFirstPlayerChipInLine = 0;

            if (numFirstPlayerChipInLine == 4)
                return WIN;
        }

        int numSecondPlayerChipInLine = 0;
        for (int i = 0; i < width && n + i < height; ++i)
        {
            Chip chip = field.at(n + i).at(i);
            if (chip == _secondPlayerChip)
                ++numSecondPlayerChipInLine;
            else
                numSecondPlayerChipInLine = 0;

            if (numSecondPlayerChipInLine == 4)
                return LOSE;
        }
    }

    for (int n = 0; n < width; ++n)
    {
        int numFirstPlayerChipInLine = 0;
        for (int i = 0; n + i < height && i < width; ++i)
        {
            Chip chip = field.at(n + i).at(i);
            if (chip == _firstPlayerChip)
                ++numFirstPlayerChipInLine;
            else
                numFirstPlayerChipInLine = 0;

            if (numFirstPlayerChipInLine == 4)
                return WIN;
        }

        int numSecondPlayerChipInLine = 0;
        for (int i = 0; n + i < height && i < width; ++i)
        {
            Chip chip = field.at(n + i).at(i);
            if (chip == _secondPlayerChip)
                ++numSecondPlayerChipInLine;
            else
                numSecondPlayerChipInLine = 0;

            if (numSecondPlayerChipInLine == 4)
                return LOSE;
        }
    }

    return CONTINUES;
}
