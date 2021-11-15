#ifndef WORKFLOW_EXECUTOR_FACTORY_H
#define WORKFLOW_EXECUTOR_FACTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "../Workers/inc/Worker.h"
#include "../include/Workers.h"

class Factory
{
public:
    Factory();
    Worker* createWorker(std::vector<std::string> params);

protected:
    Worker* getWorker(std::string type);
    std::map <std::string, Worker*> workers;
};


#endif //WORKFLOW_EXECUTOR_FACTORY_H
