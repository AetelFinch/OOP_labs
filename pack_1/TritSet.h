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

    class ProxyTritSet
    {
        friend class TritSet;
    public:
        TritSet& operator= (Trit trit);
//        ProxyTritSet& operator= (const ProxyTritSet &set);

    private:
        TritSet &_tritSet;
        size_t _pos;

        ProxyTritSet(TritSet &tritSet, size_t pos) : _tritSet(tritSet), _pos(pos) {}
    };

    size_t length();
    size_t capacity();
    size_t cardinality(Trit value);
    unordered_map< Trit, int, hash<int> > cardinality();
    void trim(size_t lastIndex);
    void shrink();

    ProxyTritSet operator[] (size_t pos);
    Trit operator[] (size_t pos) const;

    TritSet &operator= (const TritSet &tritSet);

private:
    uint *trit_array;
    size_t _length;
    size_t _capacity;
    size_t _words;
    const uint _mask = 0b11;
    const ptrdiff_t _trits_per_word = 4 * sizeof(uint);

    TritSet& _set_trit(size_t pos, Trit trit);
    Trit _get_trit(size_t pos) const;
    size_t _get_num_words(size_t trits_reserved);
    size_t _get_actual_length();
};

#endif //PACK_1_TRITSET_H
