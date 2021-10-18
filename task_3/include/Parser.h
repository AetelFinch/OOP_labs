#ifndef TASK_3_PARSER_H
#define TASK_3_PARSER_H

#include <vector>
#include <string>
#include <map>


class Parser
{
public:
    ~Parser();
    Parser(const std::string& filename);

    int get_current_command();

private:
    std::map<int, std::vector<std::string>> *_desk;
    std::vector<int> *_commands;
    size_t _count_commands;
    size_t _cur_command;

    bool _is_params_correct(std::vector<std::string> params);
    void _push_params_to_desk(std::vector<std::string> params);

    bool _is_workflow_correct(std::vector<std::string> workflow);
    void _push_workflow_to_commands(std::vector<std::string> workflow);

    bool _is_correct_IO_files_order();
};

#endif //TASK_3_PARSER_H
