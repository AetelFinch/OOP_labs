#include "Controller.h"

Controller::Controller(Model *model)
{
    _model = model;
}

void Controller::start()
{
    while(true)
    {
        GameState state = _model->makeTurn();

        if (state != CONTINUES)
            break;
    }
}
