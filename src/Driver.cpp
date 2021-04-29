#include <iostream>
#include "Hash.h"
#include "HashTable.h"
#include "ExampleObj.h"

#define TABLE_SIZE 11

int main() {
    ExampleObj obj{"CSC240GroupLab"};
    Hash<ExampleObj> myHF;
    std::cout << myHF(obj) % TABLE_SIZE; // prints 6

    return 0;
}