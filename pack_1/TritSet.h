#ifndef PACK_1_TRITSET_H
#define PACK_1_TRITSET_H

#include <cstddef>
#include <unordered_map>

using namespace std;
typedef unsigned int uint;

enum Trit{False, Unknown, True};

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

private:
    uint *trit_array;
    size_t _length;
    size_t _capacity;
};

#endif //PACK_1_TRITSET_H
