#include <gtest.h>
#include <cassert>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include "TritSet.h"

using namespace std;

//Place for tests
int main()
{
    int *a = (int*)calloc(sizeof(int), 5);
    a[0] = 1;
    a[2] = 3;

    TritSet set(100);

    size_t allocLength = set.capacity();

    assert(allocLength >= 1000*2 / 8 / sizeof(uint) );

    cout << "first" << endl;
    set[100] = True;
    set[0] = True;

    set[120] = Unknown;
    assert(allocLength == set.capacity());

    cout << "second" << endl;

    set[120] = True;
    assert(allocLength < set.capacity());

    cout << "third" << endl;

    allocLength = set.capacity();
    set[120] = Unknown;

    cout << "fourth" << endl;

    set[101] = False;
    assert(allocLength == set.capacity());

    cout << "fifth" << endl;

    TritSet copy = set;

    cout << "sixth" << endl;

    return 0;
}