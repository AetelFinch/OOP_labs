#include <iostream>
#include <fstream>

#include "Parser.h"
#include "Workers.h"

int main()
{
    std::string filename = "../test/configuration.txt";
    Parser parser(filename);

    File file;
    while (true)
    {
        int id = parser.get_current_command();
        if (id == -1)
            break;

//        Worker worker (parser.get_params(id));
//        Worker *worker =
//        file = worker->compute(file);
    }

    return 0;
}
