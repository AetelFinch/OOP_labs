#include <new>
#include <algorithm>
#include "TritSet.h"

#define TRITS_IN_BYTE 4

using namespace std;


TritSet::TritSet(int trits_reserved)
{
    if (trits_reserved < 0)
        throw invalid_argument("incorrect reserve_size");

    size_t num_cells = trits_reserved / TRITS_IN_BYTE * sizeof(uint);

    trit_array = new uint[num_cells];
    fill (trit_array, trit_array + num_cells * sizeof(uint), Unknown);

    _capacity = num_cells * sizeof(uint) * TRITS_IN_BYTE;
    _previous_capacity = _capacity;
    _length = 0;
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

Trit &TritSet::operator[](size_t pos)
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
