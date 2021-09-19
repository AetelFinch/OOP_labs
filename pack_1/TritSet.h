#ifndef PACK_1_TRITSET_H
#define PACK_1_TRITSET_H

#include <cstddef>
#include <unordered_map>

using namespace std;
using uint = unsigned int;

enum Trit{Unknown, False, True};

class TritSet
{
public:
    explicit TritSet(int trits_reserved=0);
    ~TritSet();

    size_t length();
    size_t capacity();
    size_t cardinality(Trit value);
    unordered_map< Trit, int, hash<int> > cardinality();
    void trim(size_t lastIndex);
    void shrink();

    TritSet& operator[] (ptrdiff_t pos);
    TritSet& operator= (Trit value);
    TritSet& operator= (const TritSet &set);

private:
    uint *trit_array;
    size_t _length;
    size_t _capacity;
    size_t _words;
    ptrdiff_t _required_trit_pos;
    const uint _mask = 0b11;
    const ptrdiff_t _trits_per_word = 4 * sizeof(uint);

    void _set_trit(ptrdiff_t pos, Trit trit);
    size_t _get_num_words(int trits_reserved);
    size_t _get_actual_length();
};

#endif //PACK_1_TRITSET_H
