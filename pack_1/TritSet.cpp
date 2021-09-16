#include <new>
#include <algorithm>
#include "TritSet.h"

using namespace std;


TritSet::TritSet(int reserve_size)
{
    if (reserve_size < 0)
        throw invalid_argument("incorrect reserve_size");

    trit_array = new uint (reserve_size);
    fill (0, reserve_size, Unknown);

    _length = 0;
    _capacity = reserve_size;
    _previous_capacity = reserve_size;
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

Trit &TritSet::operator[](int index)
{

}

TritSet &TritSet::operator= (const Trit &value)
{

}

TritSet &TritSet::operator= (const TritSet &set)
{
    if (&set != this)
    {

    }
    return *this;
}
