#ifndef INC_4_TO_LINE_CONSOLEVIEW_H
#define INC_4_TO_LINE_CONSOLEVIEW_H

#include <map>
#include <string>
#include <iostream>
#include <vector>

#include "View.h"

class ConsoleView : public View
{
public:
    explicit ConsoleView(Model *model);
    void update(GameState state) override;

private:
    void paintField() override;
    std::map<Chip, std::string> _chipsMap;
};


#endif //INC_4_TO_LINE_CONSOLEVIEW_H
