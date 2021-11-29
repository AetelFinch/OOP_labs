#ifndef INC_4_TO_LINE_MODEL_H
#define INC_4_TO_LINE_MODEL_H

#include "../entities/gamefield/GameField.h"
#include "../entities/player/PlayerInterface.h"
#include "../entities/arbiter/Arbiter.h"
#include "../entities/GameState.h"

class Model
{
public:
    Model(PlayerInterface *firstPlayer, PlayerInterface *secondPlayer, Arbiter *arbiter, GameField *gameField);
    GameState makeTurn();
    std::vector<std::vector<Chip>> getGameField();
    int getHeight();
    int getWidth();

private:
    GameField *_gameField;
    Arbiter *_arbiter;
    PlayerInterface *_firstPlayer;
    PlayerInterface *_secondPlayer;
};


#endif //INC_4_TO_LINE_MODEL_H
