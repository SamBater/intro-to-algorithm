#include "HashTable.hpp"
#include <iostream>
int main()
{
    HashTable<std::string, int> table;
    std::string s = "hey,i am s\n";
    std::string p = "hello,i am p\n";
    table.insert(s, 52);
    table.insert(p, 123);
    std::cout << table[s] << std::endl;

    // HashTable<int, int> table;
    // table.insert(10, 102);
    // table.remove(10);
    // std::cout << table[10];

    //int **ptr = new int *[5];
}