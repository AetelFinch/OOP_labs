#include "Parser.h"
#include "Factory.h"

int main()
{
    std::string filename = "../test/configuration.txt";
    Parser parser(filename);

    File file;
    WorkerFactory workerFactory;
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
