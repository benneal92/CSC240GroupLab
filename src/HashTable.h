#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <cstddef>  // size_t

#include "Hash.h" // functor

template<typename T>
class HashTable {
public:
    explicit HashTable(int size = 11); 
    bool contains(const T& obj) const;
    bool insert(const T& obj);
    bool remove(const T& obj);
    void makeEmpty();

private:
    std::vector<std::list<T>> hashTable;
    int size;

    void rehash();
    size_t hashFunction(const T& obj) const;

};

/**
 * hashFunction takes an T obj and initializes a functor of T type
 * 
 * myHF is a functor and it does the hashing
 * 
 * Pre: HashTable is initialized and T has Hash functor implemented
 * Post: size_t representing hashed index is returned. State of Hashtable is unchanged
 */ 
template<typename T>
size_t HashTable<T>::hashFunction(const T& obj) const {
    static Hash<T> myHF;
    return myHF(obj) % hashTable.size();
}

/**
 * Pre:
 * Post:
 */ 
template<typename T>
HashTable<T>::HashTable(int size) {

}

/**
 * Pre:
 * Post:
 */ 
template<typename T>
bool HashTable<T>::contains(const T& obj) const {

}

/**
 * Pre:
 * Post:
 */ 
template<typename T>
bool HashTable<T>::insert(const T& obj) {

}

/**
 * Pre:
 * Post:
 */ 
template<typename T>
bool HashTable<T>::remove(const T& obj) {

}

/**
 * Pre:
 * Post:
 */ 
template<typename T>
void HashTable<T>::makeEmpty() {

}

#endif /* HASHTABLE_H */