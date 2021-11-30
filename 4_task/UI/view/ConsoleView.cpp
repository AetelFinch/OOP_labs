#include "ConsoleView.h"

ConsoleView::ConsoleView(Model *model) : View(model)
{
    _chipsMap[NONE] = ".";
    _chipsMap[BLACK] = "x";
    _chipsMap[RED] = "o";
}

void ConsoleView::update(GameState state)
{
    paintField();

    if (state == CONTINUES)
    {
        std::cout << "next turn" << std::endl;
    }
    else if (state == WIN)
    {
        std::cout << "you win!" << std::endl;
    }
    else if (state == LOSE)
    {
        std::cout << "you lose" << std::endl;
    }
    else if (state == DRAW)
    {
        std::cout << "draw" << std::endl;
    }
    else
    {
        throw std::runtime_error("incorrect game state");
    }
}

void ConsoleView::paintField()
{
    std::vector<std::vector<Chip>> field = _model->getGameField();

    for (int i = _model->getHeight() - 1; i >= 0; --i)
    {
        for (int j = 0; j < _model->getWidth(); ++j)
        {
            std::cout << _chipsMap.at(field.at(i).at(j)) << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 7; ++i)
        std::cout << i << " ";
    std::cout << std::endl;
}
