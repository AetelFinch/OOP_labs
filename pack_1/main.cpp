#include <gtest.h>
#include <cassert>
#include <bitset>
#include "TritSet.h"

using namespace std;

//Place for tests
int main()
{
    TritSet set(100);

    size_t allocLength = set.capacity();

    assert(allocLength >= 1000*2 / 8 / sizeof(uint) );

    set[1000000000] = Unknown;
    assert(allocLength == set.capacity());

    set[1000000000] = True;
    assert(allocLength < set.capacity());

    allocLength = set.capacity();
    set[1000000000] = Unknown;
    set[1000000] = False;
    assert(allocLength == set.capacity());
    

    return 0;
}