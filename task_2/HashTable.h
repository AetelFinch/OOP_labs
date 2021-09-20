#ifndef TASK_2_HASHTABLE_H
#define TASK_2_HASHTABLE_H

#include <string>
#include <vector>

using namespace std;

struct Student
{
    size_t age;
    size_t weight;
};

typedef string Key;
typedef Student Value;


class HashTable
{
public:
    HashTable();
    ~HashTable();
    HashTable(const HashTable& b);
    HashTable(HashTable& b);

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b);

    void swap(HashTable& b);

    void clear();

    bool erase(const Key& k);

    bool insert(const Key& k, const Value& v);

    bool contains(const Key& k) const;

    size_t size() const;
    bool empty() const;

    Value& operator[](const Key& k);
    Value& at(const Key& k);
    const Value& at(const Key& k) const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);

private:
    vector <Value> _table;
    size_t _table_size;
    size_t _occupied_cells;
};

bool operator==(const HashTable& a, const HashTable& b);
bool operator!=(const HashTable& a, const HashTable& b);


#endif //TASK_2_HASHTABLE_H
