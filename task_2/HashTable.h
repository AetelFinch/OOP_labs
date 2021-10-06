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
    HashTable(HashTable&& b) noexcept;

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b) noexcept;

    void swap(HashTable& b);  // Exchanges the values of two hash tables

    void clear();  // Cleans the container

    bool erase(const Key& k);  // Deletes an element by the specified key

    bool insert(const Key& k, const Value& v);  // Inserting into the container. The return value is the success of the insertion

    bool contains(const Key& k) const;  // Checking for the presence of a value for a given key

    size_t size() const;  // Returns number of elements in a hash table
    bool empty() const;  // Returns true if a hash table is empty, otherwise returns false

    // Returns the value by key. If there is no key in the container,
    // inserts the value created by the default constructor into the container
    // and returns a reference to it
    Value& operator[](const Key& k);

    // Returns the value by key. Throws an exception on failure.
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
