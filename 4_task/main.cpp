#include "entities/gamefield/GameField.h"
#include "entities/arbiter/Arbiter.h"
#include "entities/player/PlayerInterface.h"
#include "entities/player/HumanPlayerImpl.h"
#include "entities/player/BotPlayerImpl.h"
#include "interactor/Model.h"
#include "UI/controller/Controller.h"
#include "UI/view/View.h"
#include "UI/view/ConsoleView.h"


int main()
{
    auto gameField = new GameField();

    PlayerInterface *firstPlayer = new HumanPlayerImpl(gameField, RED);
    PlayerInterface *secondPlayer = new BotPlayerImpl(gameField, BLACK);

    auto arbiter = new Arbiter(RED, BLACK, gameField);

    auto model = new Model(firstPlayer, secondPlayer, arbiter, gameField);

    View *view = new ConsoleView(model);
    auto controller = new Controller(model);

    model->registerObserver(view);
    model->notifyObservers(CONTINUES);

    controller->start();

    return 0;
}
