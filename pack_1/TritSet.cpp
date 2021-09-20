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

TritSet::ProxyTritSet TritSet::operator[](size_t pos)
{
    return ProxyTritSet{*this, pos};
}

Trit TritSet::operator[](size_t pos) const
{
    return _get_trit(pos);
}

TritSet& TritSet::ProxyTritSet::operator=(const Trit _trit)
{
    if (_pos <= _tritSet._capacity)
    {
        _tritSet._set_trit(_pos, _trit);
    }
    else if (_pos > _tritSet._capacity && _trit != Unknown)
    {
        size_t num_words = _tritSet._get_num_words(_pos);
        _tritSet.trit_array = (uint*)realloc(_tritSet.trit_array, num_words * sizeof(uint));
        memset(_tritSet.trit_array + _tritSet._words * sizeof(uint), Unknown, (num_words - _tritSet._words) * sizeof(uint));

        _tritSet._set_trit(_pos, _trit);

        _tritSet._words = num_words;
        _tritSet._capacity = num_words * _tritSet._trits_per_word;
        _tritSet._length = _tritSet._get_actual_length();
    }

    return this->_tritSet;
}

TritSet &TritSet::operator=(const TritSet &tritSet)
{
    if (&tritSet != this)
    {
        _length = tritSet._length;
        _capacity = tritSet._capacity;
        _words = tritSet._words;

        free(trit_array);
        trit_array = (uint*)calloc(_words, sizeof(uint));
        memcpy(trit_array, tritSet.trit_array, _words * sizeof(uint));
    }

    return *this;
}

//TritSet::ProxyTritSet &TritSet::ProxyTritSet::operator=(const TritSet::ProxyTritSet &set)
//{
//    if (this != &set)
//    {
//        _tritSet._length = set._tritSet._length;
//        _tritSet._capacity = set._tritSet._capacity;
//        _tritSet._words = set._tritSet._words;
//
//        free(_tritSet.trit_array);
//        _tritSet.trit_array = (uint*)calloc(_tritSet._words, sizeof(uint));
//        memcpy(_tritSet.trit_array, set._tritSet.trit_array, _tritSet._words * sizeof(uint));
//    }
//
//    return *this;
//}


TritSet& TritSet::_set_trit(size_t pos, Trit trit)
{
    size_t num_trit = (pos % _trits_per_word) * 2;
    size_t num_cell = pos / _trits_per_word;

    trit_array[num_cell] &= (~(_mask << num_trit));
    trit_array[num_cell] |= (trit << num_trit);

    return *this;
}

Trit TritSet::_get_trit(size_t pos) const
{
    if (_length < pos)
        return Unknown;

    return Trit((trit_array[pos / _trits_per_word] >> 2 * (pos % _trits_per_word)) & _mask);
}

size_t TritSet::_get_num_words(size_t trits_reserved)
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


