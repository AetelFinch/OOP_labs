#ifndef WORKFLOW_EXECUTOR_SORT_H
#define WORKFLOW_EXECUTOR_SORT_H

#include <algorithm>

#include "../inc/Worker.h"

class Sort final : public Worker
{
public:
    File& compute(File& file) override
    {
        std::sort(file.begin(), file.end());
        return file;
    }

    ~Sort() override = default;

    void setParams(const std::vector<std::string> &params) override
    {
        for (auto i = params.begin() + 1; i != params.end(); ++i)
            _params.push_back(*i);
    }

private:
    std::vector<std::string> _params;
};


#endif //WORKFLOW_EXECUTOR_SORT_H
