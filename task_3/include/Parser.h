#ifndef TASK_3_PARSER_H
#define TASK_3_PARSER_H

#include <vector>
#include <string>
#include <map>

using File = std::list<std::string>>;

class Parser
{
public:
    Parser();
    ~Parser();
    Parser(std::string filename);

//    Parser& operator=()

    int get_current_command();

private:
    std::map<int, std::vector<std::string>> *_desk;
    std::vector<int> *_commands;
    bool _is_file_exist;
    size_t _cur_command;

    bool _is_params_correct(std::vector<std::string> params);
    void _push_params_to_desk(std::vector<std::string> params);

    bool _is_workflow_correct(std::vector<std::string> workflow);
    void _push_workflow_to_commands(std::vector<std::string> workflow);
};

#endif //TASK_3_PARSER_H
