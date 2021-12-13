#include "Model.h"

Model::Model(PlayerInterface *firstPlayer, PlayerInterface *secondPlayer, Arbiter *arbiter, GameField *gameField)
{
    _gameField = gameField;
    _arbiter = arbiter;
    _players.push_back(firstPlayer);
    _players.push_back(secondPlayer);
}

GameState Model::makeTurn()
{
    _players[_currentPlayer]->dropChip();
    GameState state = _arbiter->getGameState();
    notifyObservers(state);

    int tmp = _currentPlayer;
    _currentPlayer = _previousPlayer;
    _previousPlayer = tmp;

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

