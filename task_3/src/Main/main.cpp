#include "../include/workflow.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "Please, enter the configuration file" << std::endl;
        exit(1);
    }

    if (argc > 2)
    {
        std::cout << "Too many files" << std::endl;
        exit(2);
    }

    std::string filename = argv[1];
    Parser parser(filename);

    File file;
    Factory workerFactory;
    while (true)
    {
        int id = parser.get_current_command();
        if (id == -1)
            break;

        Worker *worker = workerFactory.createWorker(parser.get_params(id));
        file = worker->compute(file);
    }

    return 0;
}
