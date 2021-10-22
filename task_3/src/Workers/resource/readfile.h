#ifndef WORKFLOW_EXECUTOR_READFILE_H
#define WORKFLOW_EXECUTOR_READFILE_H

#include <fstream>

#include "../inc/Worker.h"

class Readfile final : public Worker
{
public:
    File& compute(File& file) override
    {
        std::ifstream opened_file(_params.at(0));
        if (!opened_file.is_open())
        {
            throw IncorrectArgumentsError();
        }

        std::string line;
        while (std::getline(opened_file, line))
        {
            file.push_back(line);
        }

        return file;
    }

    ~Readfile() override = default;

    void setParams(const std::vector<std::string> &params) override
    {
        for (auto i = params.begin() + 1; i != params.end(); ++i)
            _params.push_back(*i);
    }

private:
    std::vector<std::string> _params;
};

#endif //WORKFLOW_EXECUTOR_READFILE_H
