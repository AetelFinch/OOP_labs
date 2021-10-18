#ifndef TASK_3_WORKER_H
#define TASK_3_WORKER_H

#include <vector>
#include <string>

using File = std::vector<std::string>;

class Worker
{
public:
    virtual File& compute(File& file);
    virtual ~Worker() { }

    static Worker *createWorker(int id);
};

#endif //TASK_3_WORKER_H
