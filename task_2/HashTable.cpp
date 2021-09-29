#include <algorithm>
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

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;

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

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;

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

    _table_size = b._table_size;
    _number_elements = b._number_elements;

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;

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
    _table_size = 0;
    _number_elements = 0;

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;
}

bool HashTable::erase(const Key &k)
{
    size_t idx = _hash(k);

    for (auto it = _table->at(idx).begin(); it != _table->at(idx).end(); ++it)
    {
        if (it->first == k)
        {
            _table->at(idx).erase(it);
            return true;
        }
    }
    return false;
}

bool HashTable::insert(const Key &k, const Value &v)
{
    if (contains(k))
        return false;

    size_t idx = _hash(k);
    _table->at(idx).push_back({k, v});

    ++_number_elements;

    return true;
}

bool HashTable::contains(const Key &k)
{
    size_t idx = _hash(k);

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

size_t HashTable::_hash(const Key& key) const
{
    return (hash<string>{}(key) % _table_size);
}

bool HashTable::empty() const
{
    return _number_elements > 0;
}

