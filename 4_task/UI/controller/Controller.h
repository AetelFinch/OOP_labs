#ifndef INC_4_TO_LINE_CONTROLLER_H
#define INC_4_TO_LINE_CONTROLLER_H

#include "../../interactor/Model.h"
#include "../../entities/GameState.h"

class Controller
{
public:
    explicit Controller(Model *model);
    void start();

private:
    Model *_model;
};


#endif //INC_4_TO_LINE_CONTROLLER_H
