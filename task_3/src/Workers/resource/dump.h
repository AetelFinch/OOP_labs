#ifndef WORKFLOW_EXECUTOR_DUMP_H
#define WORKFLOW_EXECUTOR_DUMP_H

#include "../inc/Worker.h"

class Dump final : public Worker
{
public:
    File& compute(File& file) override
    {
        std::ofstream opened_file(_params.at(0));

        for (const auto& line : file)
            opened_file << line << std::endl;

        return file;
    }

    ~Dump() override = default;

    void setParams(const std::vector<std::string> &params) override
    {
        for (auto i = params.begin() + 1; i != params.end(); ++i)
            _params.push_back(*i);
    }

private:
    std::vector<std::string> _params;
};


#endif //WORKFLOW_EXECUTOR_DUMP_H
