#ifndef PACK_1_TRITSET_H
#define PACK_1_TRITSET_H

#include <cstddef>
#include <unordered_map>

#define uint unsigned int

using namespace std;

enum Trit{False=-1, Unknown=0, True=1};

class TritSet
{
public:
    explicit TritSet(int reserve_size=0);
    ~TritSet();

    size_t length();
    size_t capacity();
    size_t cardinality(Trit value);
    unordered_map< Trit, int, hash<int> > cardinality();
    void trim(size_t lastIndex);
    void shrink();

    Trit& operator[] (size_t index);
    TritSet& operator= (const Trit &value);
    TritSet& operator= (const TritSet &set);

private:
    uint *trit_array;
    size_t _length;
    size_t _capacity;
    size_t _previous_capacity;
};

#endif //PACK_1_TRITSET_H
