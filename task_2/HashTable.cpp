#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    _table_size = 32;
    _occupied_cells = 0;
    _table = new vector<pair<Key, Value>>(_table_size);
}

HashTable::~HashTable()
{
    delete _table;
}

HashTable::HashTable(HashTable &b)
{
    _table_size = b._table_size;
    _occupied_cells = b._occupied_cells;

    delete _table;
    _table = b._table;
}

HashTable::HashTable(const HashTable &b)
{
    _table_size = b._table_size;
    _occupied_cells = b._occupied_cells;

    delete _table;
    _table = b._table;
}

HashTable &HashTable::operator=(const HashTable &b)
{
    if (this == &b)
        return *this;

    _table_size = b._table_size;
    _occupied_cells = b._occupied_cells;

    delete _table;
    _table = b._table;
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

    vector<pair<Key, Value>> *tmp = _table;
    _table = b._table;
    b._table = tmp;
}

void HashTable::clear()
{
    _table_size = 32;
    _occupied_cells = 0;

    delete _table;
    _table = new vector<pair<Key, Value>>(_table_size);
}

