#ifndef WORKFLOW_EXECUTOR_REPLACE_H
#define WORKFLOW_EXECUTOR_REPLACE_H

#include "../inc/Worker.h"

class Replace final : public Worker
{
public:
    File& compute(File& file) override
    {
        for (int i = 0; i < file.size(); ++i)
        {
            file.at(i) = StringReplacer(file.at(i), _params.at(0), _params.at(1));
        }
        return file;
    }

    ~Replace() override = default;

    void setParams(const std::vector<std::string> &params) override
    {
        for (auto i = params.begin() + 1; i != params.end(); ++i)
            _params.push_back(*i);
    }

    std::string StringReplacer(const std::string& inputStr, const std::string& src, const std::string& dst)
    {
        std::string result(inputStr);

        size_t pos = result.find(src);
        while(pos != std::string::npos) {
            result.replace(pos, src.size(), dst);
            pos = result.find(src, pos);
        }

        return result;
    }

private:
    std::vector<std::string> _params;
};


#endif //WORKFLOW_EXECUTOR_REPLACE_H
