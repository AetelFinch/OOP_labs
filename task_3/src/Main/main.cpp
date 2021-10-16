#include <iostream>
#include <fstream>

#include "Parser.h"
#include "Workers.h"

int main()
{
    std::string filename = "../test/configuration.txt";
    Parser parser(filename);

    std::cout << "Ok";

    return 0;
}
