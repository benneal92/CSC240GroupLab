#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <cstddef>
#include <climits>
#include <cmath> 

#include "Hash.h" 

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
    int nextPrime(int num);
    bool isPrime(int num);

};

/**
 * Pre: HashTable is initialized and T has Hash functor implemented
 * Post: size_t representing hashed index is returned. State of Hashtable is unchanged
 * Data Members: hashTable
 * Member Functions: N/A
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
HashTable<T>::HashTable(int hashTableSize) {

}

/**
 * Pre:HashTable is initialized
 * Post: returns whether object is in or not in the table
 * Data Members: hashTable
 * Member Functions: hashFunction
 */ 
template<typename T>
bool HashTable<T>::contains(const T& obj) const {
    auto found_obj = false;
    auto location = hashTable[hashFunction(obj)];
    found_obj = std::find(location.begin(),location.end(), obj);
    if(found_obj != location.end()){
        return true;
    }
    else
        return false;
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
 * Pre:List has been initialized.
 * Post:The list is empty.
 * Data Members:hashtable, size.
 * Member Functions:Makes the list Empty.
 */ 
template<typename T>
void HashTable<T>::makeEmpty() {
   size = 0;
   for(int i = 0; i<hashTable.size();i++){
	 hashTable.clear(); 
   }
}
/**
 * Pre:
 * Post:
 * Data Members:size
 * Member Functions:
 */ 
template<typename T>
int HashTable<T>::getSize() const {
	return size;
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

/**
 * Pre: HashTable is initialized
 * Post: returns prime number or throws exception. State of HashTable is not changed
 * Data Members: N/A
 * Member Functions: isPrime
 */ 
template<typename T>
int HashTable<T>::nextPrime(int num) {
    while(++num < INT_MAX) 
        if(isPrime(num))
            return num;
    
    throw std::overflow_error("overflow: nextPrime greater than INT_MAX");
}

/**
 * Pre: HashTable is initialized
 * Post: returns true if number is prime and false otherwise
 * Data Members: N/A
 * Member Functions: N/A
 */  
template<typename T>
bool HashTable<T>::isPrime(int num) {
    if(num == 2)
        return true;

    if(num % 2 == 0 || num < 3)    
        return false;

    int sqrtOfNum = std::sqrt(num);

    for(int i = 3; i <= sqrtOfNum; i += 2)
        if(num % i == 0)
            return false;
    
    return true;
}

#endif /* HASHTABLE_H */
