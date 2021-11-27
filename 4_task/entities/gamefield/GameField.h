#ifndef INC_4_TO_LINE_GAMEFIELD_H
#define INC_4_TO_LINE_GAMEFIELD_H

#include <vector>
#include "../Chip.h"

class GameField
{
public:
    GameField();
    int dropChip(int pos, Chip chip);
    std::vector<std::vector<Chip>> getField();
    int getHeight() const;
    int getWidth() const;

private:
    const int _height = 6;
    const int _width = 7;
    std::vector<std::vector<Chip>> _field;
};


#endif //INC_4_TO_LINE_GAMEFIELD_H
