#ifndef TASK_3_WORKER_H
#define TASK_3_WORKER_H

#include <vector>
#include <string>

#include "../../Exception/Exceptions.h"

using File = std::vector<std::string>;

class Worker
{
public:
    virtual File& compute(File& file) { }
    virtual ~Worker() = default;

    virtual void setParams(const std::vector<std::string> &params) { }
};

#endif //TASK_3_WORKER_H