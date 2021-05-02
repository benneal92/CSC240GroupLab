#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <cstddef>  // size_t

#include "Hash.h" // functor

template<typename T>
class HashTable {
public:
    explicit HashTable(int hashTableSize = 11); 
    bool contains(const T& obj) const;
    bool insert(const T& obj);
    bool remove(const T& obj);
    void makeEmpty();
    int getSize() const;

private:
    std::vector<std::list<T>> hashTable;
    int size; 

    void rehash();
    size_t hashFunction(const T& obj) const;

    // some functions to test for prime and get the next prime

};

/**
 * hashFunction takes an T obj and initializes a functor of T type
 * 
 * myHF is a functor and it does the hashing
 * 
 * Pre: HashTable is initialized and T has Hash functor implemented
 * Post: size_t representing hashed index is returned. State of Hashtable is unchanged
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
size_t HashTable<T>::hashFunction(const T& obj) const {
    static Hash<T> myHF;
    return myHF(obj) % hashTable.size();
}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
HashTable<T>::HashTable(int hashTableSize ) {

}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
bool HashTable<T>::contains(const T& obj) const {

}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
bool HashTable<T>::insert(const T& obj) {

}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
bool HashTable<T>::remove(const T& obj) {

}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
void HashTable<T>::makeEmpty() {

}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
int HashTable<T>::getSize() const {

}

/**
 * Pre:
 * Post:
 * Data Members:
 * Member Functions:
 */ 
template<typename T>
void HashTable<T>::rehash() {

}

#endif /* HASHTABLE_H */