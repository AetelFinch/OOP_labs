#include <vector>
#include <string>

#include "Factory.h"

Factory::Factory()
{
    workers["readfile"] = new Readfile;
    workers["writefile"] = new Writefile;
    workers["grep"] = new Grep;
    workers["sort"] = new Sort;
    workers["dump"] = new Dump;
    workers["replace"] = new Replace;
}

Worker* Factory::createWorker(std::vector<std::string> params)
{
    Worker *worker = getWorker(params.at(0));

    worker->setParams(params);

    return worker;
}

Worker *Factory::getWorker(std::string type)
{
    if (workers.find(type) != workers.end())
        return workers[type];

    throw UnknownBlockError();
}
