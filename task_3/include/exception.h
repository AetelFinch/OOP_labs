#ifndef WORKFLOW_EXECUTOR_EXCEPTION_H
#define WORKFLOW_EXECUTOR_EXCEPTION_H

#include <string>

class Exception
{
protected:
    string text;

public:
    virtual string what() = 0;
};

#endif //WORKFLOW_EXECUTOR_EXCEPTION_H
