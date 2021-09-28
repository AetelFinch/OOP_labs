#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    _table_size = 32;
    _occupied_cells = 0;
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
    _occupied_cells = b._occupied_cells;

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
    _occupied_cells = b._occupied_cells;

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
    _occupied_cells = b._occupied_cells;

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
    _occupied_cells = b._occupied_cells;

    _table = b._table;
    b._table = nullptr;

    return *this;
}

void HashTable::swap(HashTable &b)
{
    if (this == &b)
        return;

    std::swap(_table_size, b._table_size);
    std::swap(_occupied_cells, b._occupied_cells);

    std::vector<std::list<std::pair<Key, Value>>> *tmp = _table;
    _table = b._table;
    b._table = tmp;
}

void HashTable::clear()
{
    _table_size = 0;
    _occupied_cells = 0;

    for (unsigned int i = 0; i < _table_size; ++i)
    {
        _table->at(i).clear();
    }
    delete _table;
}

