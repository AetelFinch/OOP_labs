#ifndef WORKFLOW_EXECUTOR_FACTORY_H
#define WORKFLOW_EXECUTOR_FACTORY_H

#include <vector>
#include <string>
#include <iostream>

#include "../src/Workers/inc/Worker.h"
#include "Workers.h"

class Factory
{
public:
    Worker* createWorker(std::vector<std::string> params)
    {
        Worker *worker = getWorker(params.at(0));

        worker->setParams(params);

        return worker;
    }

protected:
    virtual Worker* getWorker(std::string type);
};


class WorkerFactory : public Factory
{
public:
    Worker* getWorker(std::string type) override
    {
        if (type == "readfile")
        {
            return new Readfile;
        }
        else if (type == "writefile")
        {
            return new Writefile;
        }
        else if (type == "grep")
        {
            return new Grep;
        }
        else if (type == "sort")
        {
            return new Sort;
        }
        else if (type == "dump")
        {
            return new Dump;
        }
        else if (type == "replace")
        {
            return new Replace;
        }
        else
        {
            throw UnknownBlockError();
        }
    }
};


#endif //WORKFLOW_EXECUTOR_FACTORY_H
