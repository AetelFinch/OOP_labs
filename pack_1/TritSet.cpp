#include <cassert>
#include "TritSet.h"

using namespace std;


TritSet::TritSet(int reserve_size)
{
    assert(reserve_size >= 0);

    trit_array = new uint (reserve_size);
    _length = 0;
    _capacity = reserve_size;
}

TritSet::~TritSet()
{
    delete[] trit_array;
}

size_t TritSet::length()
{
    return _length;
}

size_t TritSet::capacity()
{
    return _capacity;
}

size_t TritSet::cardinality(Trit value)
{
    return 0;
}

unordered_map<Trit, int, hash<int>> TritSet::cardinality()
{
    return {};
}

void TritSet::trim(size_t lastIndex)
{

}

void TritSet::shrink()
{

}
