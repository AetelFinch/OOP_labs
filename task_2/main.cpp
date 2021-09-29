#include <iostream>
#include <gtest.h>
#include <random>
#include "HashTable.h"

//Place fo tests
using namespace std;

class TestHashTable : public::testing::Test
{
protected:
    HashTable table;

    void SetUp()
    {
        table.insert("Max", {18, 50});
        table.insert("Vanya", {18, 76});
        table.insert("Misha", {18, 80});

        string chars = "qwertyuiopasdfghjklzxcvbnm";
        for (auto i : chars)
        {
            string x(1, i);
            table.insert(x, {1, 1});
        }
    }

    void TearDown() {}
};


TEST_F(TestHashTable, TestContains)
{
    ASSERT_TRUE(table.contains("Max"));
    ASSERT_TRUE(table.contains("Misha"));
    ASSERT_TRUE(table.contains("Vanya"));
    ASSERT_TRUE(table.contains("a"));
    ASSERT_FALSE(table.contains("Timur"));
    ASSERT_FALSE(table.contains("Roy"));
    ASSERT_FALSE(table.contains("qwerty"));
}
//    cout << table.contains("Max") << endl;
//    cout << table.contains("George") << endl;
//    table.erase("Max");
//    cout << table.contains("Max") << endl;