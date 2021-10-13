#include "../../include/Parser.h"

class RuntimeError : public Exception
{
public:
    RuntimeError()
    {
        text = "Error. Runtime Exception";
    }

    RuntimeError(string _text) { text = _text; }

    string what() { return text; }
};

class IncorrectArgumentsError final : public RuntimeError
{
public:
    IncorrectArgumentsError()
    {
        text = "Incorrect arguments was passed to block";
    }

    IncorrectArgumentsError(string _text) { text = _text; }

    string what() { return text; }
};