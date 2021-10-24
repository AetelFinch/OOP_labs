#ifndef WORKFLOW_EXECUTOR_GREP_H
#define WORKFLOW_EXECUTOR_GREP_H

#include <string>
#include "../inc/Worker.h"

class Grep final : public Worker
{
public:
    File& compute(File& file) override
    {
        std::string word = _params.at(0);
        for (auto line = file.begin(); line != file.end(); ++line)
        {
            if (line->find(word) == std::string::npos)
            {
                file.erase(line);
                --line;
            }
        }
        return file;
    }

    ~Grep() override = default;

    void setParams(const std::vector<std::string> &params) override
    {
        for (auto i = params.begin() + 1; i != params.end(); ++i)
            _params.push_back(*i);
    }

private:
    std::vector<std::string> _params;
};


#endif //WORKFLOW_EXECUTOR_GREP_H
