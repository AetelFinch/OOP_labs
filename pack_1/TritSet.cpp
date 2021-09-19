#include <new>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "TritSet.h"

using namespace std;


TritSet::TritSet(int trits_reserved)
{
    if (trits_reserved < 0)
        throw invalid_argument("incorrect reserve_size");

    size_t num_words = _get_num_words(trits_reserved);
    trit_array = (uint*)calloc(num_words, sizeof(uint));

    _capacity = num_words * _trits_per_word;
    _required_trit_pos = -1;
    _length = 0;
    _words = num_words;
}

TritSet::~TritSet()
{
    free(trit_array);
    trit_array = nullptr;
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

TritSet &TritSet::operator[](ptrdiff_t pos)
{
    _required_trit_pos = pos;
    return *this;
}

TritSet &TritSet::operator= (Trit value)
{
    if (_required_trit_pos <= _capacity)
    {
        _set_trit(_required_trit_pos, value);
    }
    else if (_required_trit_pos > _capacity && value != Unknown)
    {
        size_t num_words = _get_num_words(_required_trit_pos);
        trit_array = (uint*)realloc(trit_array, num_words * sizeof(uint));
        memset(trit_array + _words, Unknown, (num_words - _words) * sizeof(uint));

        _set_trit(_required_trit_pos, value);

        _capacity = num_words * _trits_per_word;
        _length = _get_actual_length();
        _required_trit_pos = -1;
        _words = num_words;
    }
    return *this;
}

TritSet &TritSet::operator= (const TritSet &set)
{
    if (&set != this)
    {
        _length = set._length;
        _capacity = set._capacity;
        _words = set._words;
        _required_trit_pos = set._required_trit_pos;

        free(trit_array);
        trit_array = (uint*)calloc(_words, sizeof(uint));
        memcpy(trit_array, set.trit_array, _words * sizeof(uint));
    }
    return *this;
}

void TritSet::_set_trit(ptrdiff_t pos, Trit trit)
{
    size_t num_trit = (pos % _trits_per_word) * 2;
    size_t num_cell = pos / _trits_per_word;

    trit_array[num_cell] &= (~(_mask << num_trit));
    trit_array[num_cell] |= (trit << num_trit);
}

size_t TritSet::_get_num_words(int trits_reserved)
{
    size_t num_words = trits_reserved / _trits_per_word;
    if (num_words * _trits_per_word < trits_reserved)
        ++num_words;

    return num_words;
}

size_t TritSet::_get_actual_length()
{
    size_t last_nonempty_word_pos = _words - 1;

    while (last_nonempty_word_pos != 0 && trit_array[last_nonempty_word_pos] == 0)
        --last_nonempty_word_pos;

    for (ptrdiff_t trit_pos = _trits_per_word - 1; trit_pos >= 0; --trit_pos)
    {
        size_t  trit_mask = _mask << (trit_pos * 2);
        Trit trit = Trit(trit_array[last_nonempty_word_pos] & trit_mask);

        if (trit != Unknown)
            return last_nonempty_word_pos * _trits_per_word + (trit_pos + 1);
    }
    return 0;
}



