#include <iostream>
#include <fstream>
#include <list>
#include <string>

int main()
{
    std::list <std::string> l;

    return 0;
}

// хранить в uint по sizeof(uint) / 2 тритов
// учитывать разный размер uint на разных платформах
// TritSet set(1000); - выделяет память для 1000 тритов (max value = 3^1000 - 1)
//