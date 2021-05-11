#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <cstddef>
#include <climits>
#include <cmath>
#include <algorithm> 
#include <iostream>

#include "Hash.h" 
#include "HashTableIterator.h"

template<typename T>
class HashTable {
public:
	explicit HashTable(int hashTableSize = 11);
	bool contains(const T &obj) const;
	bool insert(const T &obj);
	bool remove(const T &obj);
	void makeEmpty();
	int getSize() const;
	bool isEmpty();
	float loadFactor() const;
	int findCollisions() const;
	template<class U>
	friend std::ostream& operator<<(std::ostream &out, const HashTable<U> &ht);

	HashTableIterator<T> begin();
	HashTableIterator<T> end();

private:
	std::vector<std::list<T>> hashTable;
	int size;
	void rehash();
	size_t hashFunction(const T &obj) const;
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
size_t HashTable<T>::hashFunction(const T &obj) const {
	static Hash<T> myHF;
	return myHF(obj) % hashTable.size();
}

/**
 * Pre: HashTable is not initialized
 * Post: HashTable is initialized with prime number for table size
 * Data Members: size, hashTable
 * Member Functions: isPrime, nextPrime
 */
template<typename T>
HashTable<T>::HashTable(int hashTableSize) :
		size { 0 } {
	if (hashTableSize < 1)
		throw std::underflow_error(
				"Error Usage: HashTable size must be greater than 0");

	if (isPrime(hashTableSize))
		hashTable.resize(hashTableSize);
	else
		hashTable.resize(nextPrime(hashTableSize));
}

/**
 * Pre: HashTable is initialized
 * Post: returns whether object is in or not in the table
 * Data Members: hashTable
 * Member Functions: hashFunction
 */
template<typename T>
bool HashTable<T>::contains(const T &obj) const {

	auto location = hashTable[hashFunction(obj)];
	return (std::find(location.begin(), location.end(), obj) != location.end());

}

/**
 * Pre: HashTable is initialized.
 * Post: returns how many collisions there are
 * Data Members: hashTable
 * Member Functions:  N/A
 */
template<typename T>
int HashTable<T>::findCollisions() const {
	int collisions = 0;
	for (auto row : this->hashTable) {
		if (row.size() > 1) {
			collisions++;
		}
	}
	return collisions;
}

/**
 * Pre: The table is constructed.
 * Post: The table may (see returned boolean) have the item inserted.
 * Data Members: hashTable, size
 * Member Functions: hashFunction
 */
template<typename T>
bool HashTable<T>::insert(const T &obj) {
	size_t index = this->hashFunction(obj);
	//std::cout << index << std::endl;
	try {
		this->hashTable.at(index).push_front(obj);
		size += 1;
		return true;
	} catch (std::exception const &e) {
		return false;
	}
}

/**
 * Pre: The table is initialized and has items inserted.
 * Post: Any items matching the given item will be removed.
 * Data Members: hashTable, size
 * Member Functions: n/a
 *
 * remove_if courtesy of: https://en.cppreference.com/w/cpp/container/list/remove
 * lambda courtesy of: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp
 */
template<typename T>
bool HashTable<T>::remove(const T &obj) {
	int removed = 0;
	// remove ALL items matching the description
	for (auto &row : this->hashTable) {
		row.remove_if([&obj, &removed](T item) {
			bool match = item == obj;
			if (match) {
				removed += 1;
			}
			return match;
		});
	}
	size -= removed;
	return removed <= 0;
}

/**
 * Pre: List has been initialized.
 * Post: The list is empty.
 * Data Members: hashTable, size.
 * Member Functions: Makes the list Empty.
 */
template<typename T>
void HashTable<T>::makeEmpty() {
	size = 0;
	for (int i = 0; i < hashTable.size(); i++) {
		hashTable.clear();
	}
}

/**
 * Pre: HashTable is initialized
 * Post: state is unchanged. Returns number of elements currently in the HashTable
 * Data Members: size
 * Member Functions: N/A
 */
template<typename T>
int HashTable<T>::getSize() const {
	return size;
}

/**
 * Pre: HashTable is initialized
 * Post: state is unchanged. Returns true if size is zero and false otherwise
 * Data Members: size 
 * Member Functions: N/A
 */
template<typename T>
bool HashTable<T>::isEmpty() {
	return size == 0;
}

/**
 * Pre: The table is initialized and items are loaded. Load factor may be above a threshold.
 * Post: The table size is expanded and all items are hashed to new locations.
 * Data Members: size, hashTable
 * Member Functions: hashFunction
 */
template<typename T>
void HashTable<T>::rehash() {
	// construct new hashTable
	std::vector<std::list<T>> newHashTable;

	// figure out next prime after doubling
	int newSize = 0;
	try {
		newSize = this->nextPrime(this->size * 2);
	} catch (std::overflow_error &e) {
		newSize = this->size; // what's a better fallback in this case? just below INT_MAX?
	}

	// resize to new doubled data structure
	newHashTable.resize(newSize);

	// rehash all items
	for (auto row : this->hashTable) {
		for (auto item : row) {
			int hash = this->hashFunction(item);
			// this will preserve the order if any of these stay in similar buckets
			newHashTable[hash].push_back(item);
		}
	}

	// finally, delete old table and point to new table
	delete this->hashTable; // I don't need to do this manually, do I?
	this->hashTable = newHashTable;
}

/**
 * Pre: The table is initialized
 * Post: The table will not change. The load factor will be returned.
 * Data Members: size, hashTable
 * Member Functions:
 */
template<typename T>
float HashTable<T>::loadFactor() const {
	if (this->size <= 0) {
		// can't divide by zero
		return 0;
	}
	int numSlots = this->hashTable.size();
	// calculate N (total items in table) / M (number of slots)
	int sum = 0;
	for (auto &row : this->hashTable)
		sum += row.size();
	return static_cast<float>(sum) / numSlots;
}

/**
 * Pre: The table is initialized
 * Post: The table will not change. An iterator pointing to the first element will be returned.
 * Data Members: hashTable
 * Member Functions:
 */
template<typename T>
HashTableIterator<T> HashTable<T>::begin() {
	return HashTableIterator<T> { this->hashTable, /* is end */false };
}

/**
 * Pre: The table is initialized
 * Post: The table will not change. An iterator pointing to past the last element will be returned.
 * Data Members: hashTable
 * Member Functions:
 */
template<typename T>
HashTableIterator<T> HashTable<T>::end() {
	return HashTableIterator<T> { this->hashTable, /* is end */true };
}

/**
 * Pre: The table is initialized
 * Post: The table will not change. It will be pretty-printed to the out stream.
 * Data Members: hashTable
 * Member Functions:
 */
template<typename U>
std::ostream& operator<<(std::ostream &out, const HashTable<U> &ht) {

	/*
	 This really doesn't work well for larger HashTables.
	 Suggest we trim this a bit :)
	 Although it'll break some tests...
	 */

	out << "HashTable [" << std::endl;
	int rowIdx = 0;
	for (auto row : ht.hashTable) {
		out << rowIdx << ">> ";
		for (auto col : row) {
			out << col << ", ";
		}
		out << std::endl;
		++rowIdx;
	}
	out << "] " << std::endl;
	return out;
}

/**
 * Pre: HashTable is initialized
 * Post: returns prime number or throws exception. State of HashTable is not changed
 * Data Members: N/A
 * Member Functions: isPrime
 */
template<typename T>
int HashTable<T>::nextPrime(int num) {
	while (++num < INT_MAX)
		if (isPrime(num))
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
	if (num == 2)
		return true;

	if (num % 2 == 0 || num < 3)
		return false;

	int sqrtOfNum = std::sqrt(num);

	for (int i = 3; i <= sqrtOfNum; i += 2)
		if (num % i == 0)
			return false;

	return true;
}

#endif /* HASHTABLE_H */
