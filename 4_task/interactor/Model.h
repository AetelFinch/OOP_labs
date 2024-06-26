#ifndef INC_4_TO_LINE_MODEL_H
#define INC_4_TO_LINE_MODEL_H

#include "Observable.h"

#include "../entities/gamefield/GameField.h"
#include "../entities/player/PlayerInterface.h"
#include "../entities/arbiter/Arbiter.h"
#include "../entities/GameState.h"

class Model : public Observable
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
    std::vector<PlayerInterface*> _players;
    int _currentPlayer = 0;
    int _previousPlayer = 1;
};


#endif //INC_4_TO_LINE_MODEL_H
