#include "Model.h"

Model::Model(PlayerInterface *firstPlayer, PlayerInterface *secondPlayer, Arbiter *arbiter, GameField *gameField)
{
    _gameField = gameField;
    _arbiter = arbiter;
    _firstPlayer = firstPlayer;
    _secondPlayer = secondPlayer;
}

GameState Model::makeTurn()
{
    _firstPlayer->dropChip();
    GameState state = _arbiter->getGameState();
    notifyObservers(state);

    if (state != CONTINUES)
        return state;

    _secondPlayer->dropChip();
    state = _arbiter->getGameState();
    notifyObservers(state);

    return state;
}

std::vector<std::vector<Chip>> Model::getGameField()
{
    return _gameField->getField();
}

int Model::getHeight()
{
    return _gameField->getHeight();
}

int Model::getWidth()
{
    return _gameField->getWidth();
}

