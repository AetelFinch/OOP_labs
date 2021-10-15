#ifndef WORKFLOW_EXECUTOR_EXCEPTIONS_H
#define WORKFLOW_EXECUTOR_EXCEPTIONS_H

#include <exception>
#include <string>

class BaseException: public std::exception {};

class ParserException: public BaseException {};

class SyntaxError: public ParserException {};

class IncorrectConfigurationFileError final: public SyntaxError {};

class WrongLocationIoBlockError final: public ParserException {};

class FileNotFoundError final: public ParserException {};

class RuntimeError: public BaseException {};

class IncorrectArgumentsError final: public RuntimeError {};

class UnknownBlockError final: public RuntimeError {};

#endif //WORKFLOW_EXECUTOR_EXCEPTIONS_H
