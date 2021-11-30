#ifndef INC_4_TO_LINE_VIEW_H
#define INC_4_TO_LINE_VIEW_H

#include "../../interactor/Model.h"
#include "../../interactor/Observer.h"

class View : public Observer
{
public:
    explicit View(Model *model) : _model(model) { };
    virtual void update(GameState state) = 0;

protected:
    virtual void paintField() = 0;
    Model *_model;
};


#endif //INC_4_TO_LINE_VIEW_H
