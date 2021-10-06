#include <algorithm>
#include <iterator>
#include <stdexcept>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    _table_size = 32;
    _number_elements = 0;
    _table = new std::vector<std::list<std::pair<Key, Value>>>(_table_size);
}

HashTable::~HashTable()
{
    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;
}

HashTable::HashTable(HashTable &b)
{
    _table_size = b._table_size;
    _number_elements = b._number_elements;
    _table = new std::vector<std::list<std::pair<Key, Value>>>(_table_size);

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i) = b._table->at(i);
    }
}

HashTable::HashTable(const HashTable &b)
{
    _table_size = b._table_size;
    _number_elements = b._number_elements;
    _table = new std::vector<std::list<std::pair<Key, Value>>>(_table_size);

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i) = b._table->at(i);
    }
}

HashTable &HashTable::operator=(const HashTable &b)
{
    if (this == &b)
        return *this;

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;

    _table_size = b._table_size;
    _number_elements = b._number_elements;

    _table = new std::vector<std::list<std::pair<Key, Value>>>(_table_size);
    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i) = b._table->at(i);
    }

    return *this;
}

HashTable &HashTable::operator=(HashTable &&b) noexcept
{
    if (this == &b)
        return *this;

    _table_size = b._table_size;
    _number_elements = b._number_elements;
    _table = b._table;

    b._table = nullptr;
    b._table_size = 0;
    b._number_elements = 0;

    return *this;
}

void HashTable::swap(HashTable &b)
{
    if (this == &b)
        return;

    std::swap(_table_size, b._table_size);
    std::swap(_number_elements, b._number_elements);

    std::vector<std::list<std::pair<Key, Value>>> *tmp = _table;
    _table = b._table;
    b._table = tmp;
}

void HashTable::clear()
{
    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    _table_size = 0;
    _number_elements = 0;

    _table->clear();
}

bool HashTable::erase(const Key &k)
{
    size_t idx = _hash(k, _table_size);

    for (auto it = _table->at(idx).begin(); it != _table->at(idx).end(); ++it)
    {
        if (it->first == k)
        {
            _table->at(idx).erase(it);
            --_number_elements;
            return true;
        }
    }
    return false;
}

bool HashTable::insert(const Key &k, const Value &v)
{
    if (contains(k))
        return false;

    if ((size_t)(_table_size * _load_factor) <= _number_elements)
        _rehash();

    size_t idx = _hash(k, _table_size);
    _table->at(idx).push_back({k, v});

    ++_number_elements;

    return true;
}

bool HashTable::contains(const Key &k) const
{
    size_t idx = _hash(k, _table_size);

    for (auto & it : _table->at(idx))
    {
        if (it.first == k)
            return true;
    }
    return false;
}

size_t HashTable::size() const
{
    return _number_elements;
}

bool HashTable::empty() const
{
    return (_number_elements == 0);
}

Value &HashTable::operator[](const Key &k)
{
    if (!contains(k))
    {
        insert(k, {0 , 0});
    }

    return _get_value(k);
}

Value &HashTable::at(const Key &k)
{
    if (!contains(k))
    {
        throw std::out_of_range("this key is not in hash table");
    }

    return _get_value(k);
}

const Value & HashTable::at(const Key &k) const
{
    if (!contains(k))
    {
        throw std::out_of_range("this key is not in hash table");
    }

    return _get_value(k);
}

bool operator==(const HashTable& a, const HashTable& b)
{
    if (a._table_size != b._table_size || a._number_elements != b._number_elements)
        return false;

    for (size_t idx = 0; idx < a._table_size; ++idx)
    {
        if (a._table->at(idx).size() != b._table->at(idx).size())
            return false;

        auto a_it = a._table->at(idx).begin();
        auto b_it = b._table->at(idx).begin();

        for (; a_it != a._table->at(idx).end(); ++a_it, ++b_it)
        {
            if (a_it->first != b_it->first || a_it->second != b_it->second)
                return false;
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b)
{
    return !(a == b);
}


size_t HashTable::_hash(const Key& key, size_t size) const
{
    return (hash<Key>{}(key) % size);
}

void HashTable::_rehash()
{
    size_t new_size = _table_size * 2;
    std::vector<std::list<std::pair<Key, Value>>> *new_table;
    new_table = new std::vector<std::list<std::pair<Key, Value>>>(new_size);

    for (size_t cell_idx = 0; cell_idx != _table_size; ++cell_idx)
    {
        for (auto &it : _table->at(cell_idx))
        {
            size_t idx = _hash(it.first, new_size);
            new_table->at(idx).push_back({it.first, it.second});
        }
        _table->at(cell_idx).clear();
    }
    _table->clear();
    _table = new_table;

    _table_size = new_size;
}

Value &HashTable::_get_value(const Key &k) const
{
    size_t idx = _hash(k, _table_size);
    for (auto & it : _table->at(idx))
    {
        if (it.first == k)
            return it.second;
    }
}