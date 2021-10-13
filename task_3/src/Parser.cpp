#include "../include/Parser.h"

#include <fstream>
#include <sstream>
#include <algorithm>

Parser::~Parser()
{
    for (auto block : *_desk)
    {
        block.second.clear();
    }
    delete _desk;
    delete _commands;
}

Parser::Parser(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        //TODO throw exception FileNotExist
        throw std::exception();
    }

    std::string check_format;
    std::getline(file, check_format);

    if (check_format != "desc")
    {
        file.close();
        //TODO throw exception IncorrectConfigurationFileError
        throw std::exception();
    }

    _desk = new std::map<int, std::vector<std::string>>;
    _commands = new std::vector<int>;

    std::string word;
    std::string block;

    while (true)
    {
        std::getline(file, block);
        if (block == "csed")
            break;

        std::istringstream iss(block, std::istringstream::in);

        std::vector<std::string> params;
        while(iss >> word) params.push_back(word);

        if (!_is_params_correct(params))
        {
            file.close();
            //TODO throw exception SyntaxError
            throw std::exception();
        }

        _push_params_to_desk(params);
    }

    std::getline(file, block);
    std::istringstream iss(block, std::istringstream::in);
    std::vector<std::string> workflow;

    while(iss >> word) workflow.push_back(word);
    if (!_is_workflow_correct(workflow))
    {
        file.close();
        //TODO throw exception SyntaxError
        throw std::exception();
    }

    _push_workflow_to_commands(workflow);

    _cur_command = 0;
}

int Parser::get_current_command()
{
    ++_cur_command;
    return _commands->at(_cur_command - 1);
}

bool Parser::_is_params_correct(std::vector<std::string> params)
{
    if (params.size() < 3)
        return false;

    if (params[1] != "=")
        return false;

    int id;
    try
    {
        id = std::stoi(params[0]);
    }
    catch (std::exception& e)
    {
        return false;
    }

    if (_desk->count(id) == 1) //duplicate id
        return false;

    return true;
}

void Parser::_push_params_to_desk(std::vector<std::string> params)
{
    int id = std::stoi(params[0]);
    std::vector<std::string> vec;
    vec.insert(vec.begin(), params.begin() + 2, params.end());
    _desk->insert(std::pair<int, std::vector<std::string>>(id, vec));
}

bool Parser::_is_workflow_correct(std::vector<std::string> workflow)
{
    if (workflow.empty())
        return false;

    if (workflow.size() % 2 == 0)
        return false;

    for (int i = 1; i < workflow.size(); i += 2)
    {
        if (workflow[i] != "->")
            return false;
    }

    for (int i = 0; i < workflow.size(); i += 2)
    {
        try
        {
            std::stoi(workflow[i]);
        }
        catch (std::exception& e)
        {
            return false;
        }
    }

    return true;
}

void Parser::_push_workflow_to_commands(std::vector<std::string> workflow)
{
    for (int i = 0; i < workflow.size(); i += 2)
    {
        int id = std::stoi(workflow[i]);
        _commands->push_back(id);
    }
}