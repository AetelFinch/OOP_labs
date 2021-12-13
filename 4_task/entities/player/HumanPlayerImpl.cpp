#include "HumanPlayerImpl.h"
#include "../../UI/controller/Controller.h"

HumanPlayerImpl::HumanPlayerImpl(GameField *gameField, Chip chip) : PlayerInterface(gameField, chip) { }

int HumanPlayerImpl::dropChip()
{
    int turn;
    int state = -1;
    while (state == -1)
    {
        std::cin >> turn;
        state = _gameField->dropChip(turn, _chip);
    }
    return state;
}
