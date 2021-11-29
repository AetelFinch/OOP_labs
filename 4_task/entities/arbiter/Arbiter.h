#ifndef INC_4_TO_LINE_ARBITER_H
#define INC_4_TO_LINE_ARBITER_H

#include <vector>

#include "../gamefield/GameField.h"
#include "../GameState.h"
#include "../Chip.h"

class Arbiter
{
public:
    Arbiter(Chip firstPlayerChip, Chip secondPlayerChip, GameField *field);
    GameState getGameState();

private:
    bool isDraw(std::vector<std::vector<Chip>> field);
    GameState checkHorizontal(const std::vector<std::vector<Chip>>& field);
    GameState checkVertical(const std::vector<std::vector<Chip>>& field);
    GameState checkLeftDiagonal(const std::vector<std::vector<Chip>>& field);
    GameState checkRightDiagonal(const std::vector<std::vector<Chip>>& field);

    Chip _firstPlayerChip;
    Chip _secondPlayerChip;
    GameField *_gameField;
};

#endif //INC_4_TO_LINE_ARBITER_H
