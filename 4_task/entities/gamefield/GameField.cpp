#include "GameField.h"

GameField::GameField()
{
    _field.reserve(_height);

    for (int i = 0; i < _height; ++i)
    {
        std::vector<Chip> line;
        line.reserve(_width);
        for (int j = 0; j < _width; ++j)
        {
            line.push_back(NONE);
        }
        _field.push_back(line);
    }
}

int GameField::getHeight() const
{
    return _height;
}

int GameField::getWidth() const
{
    return _width;
}

int GameField::dropChip(int pos, Chip chip)
{
    if (pos < 0 || pos > _width - 1)
        return -1;

    if (_field.at(_height - 1).at(pos) != NONE)
        return -1;

    int i = 0;
    while (_field.at(i).at(pos) != NONE)
        ++i;

    _field.at(i)[pos] = chip;

    return 0;
}

std::vector<std::vector<Chip>> GameField::getField()
{
    return _field;
}


