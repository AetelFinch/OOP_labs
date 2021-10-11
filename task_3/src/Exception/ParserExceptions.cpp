#include "../../include/Parser.h"

class SyntaxError : public Exception
{
public:
    SyntaxError()
    {
        text = "Error. Syntax Exception";
    }

    SyntaxError(string _text) { text = _text; }

    string what() { return text; }
};

class UnknownBlockError final : public SyntaxError
{
    UnknownBlockError()
    {
        text = "Unknown block in configuration file";
    }

    UnknownBlockError(string _text) { text = _text; }

    string what() { return text; }
};

class WrongLocationIoBlockError final : public Exception
{
public:
    WrongLocationIoBlockError()
    {
        text = "Incorrect location I/O file in configuration file";
    }

    WrongLocationIoBlockError(string _text) { text = _text; }

    string what() { return text; }
};

class FileNotFoundError final : public Exception
{
public:
    FileNotFoundError()
    {
        text = "Input file does not exist";
    }

    FileNotFoundError(string _text) { text = _text; }

    string what() { return text; }
};