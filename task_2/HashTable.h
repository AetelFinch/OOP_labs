#ifndef TASK_2_HASHTABLE_H
#define TASK_2_HASHTABLE_H

#include <string>
#include <vector>
#include <list>

struct Student
{
    size_t age;
    size_t weight;

    friend bool operator==(const Student& a, const Student& b)
    {
        if (a.age == b.age && a.weight == b.weight)
            return true;
        return false;
    }

    friend bool operator!=(const Student& a, const Student& b)
    {
        return !(a == b);
    }
};

typedef std::string Key;
typedef Student Value;


class HashTable
{
public:
    HashTable();
    ~HashTable();
    HashTable(HashTable& b);
    HashTable(const HashTable& b);

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b) noexcept;

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
    std::vector<std::list<std::pair<Key, Value>>> *_table; //vector of lists of pairs of Keys and Values
    size_t _table_size;
    size_t _number_elements;
    const double _load_factor = 0.75;

    size_t _hash(const Key& key, size_t size) const;
    void _rehash();
    Value& _get_value(const Key& k) const;
};

bool operator==(const HashTable& a, const HashTable& b);
bool operator!=(const HashTable& a, const HashTable& b);

#endif //TASK_2_HASHTABLE_H
