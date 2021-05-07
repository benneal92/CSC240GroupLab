/*
 * HashTableIterator.h
 *
 *  Created on: May 5, 2021
 *      Author: Ben
 *
 *
 *  Warning: this has no testing behind it yet. Beware!
 */

#ifndef SRC_HASHTABLEITERATOR_H_
#define SRC_HASHTABLEITERATOR_H_

#include <utility>
#include <vector>
#include <list>
#include <stdexcept>

template<class T>
class HashTableIterator {

	struct coords {
		int row;
		int column;
	};

public:
	HashTableIterator();
	HashTableIterator(std::vector<std::list<T>>&, bool);
	T& operator*();
	HashTableIterator<T>& operator++();
	bool operator!=(const HashTableIterator<T> &it) const;
	coords position;

private:
	std::vector<std::list<T>> hashTable;
	coords endPosition;
};

template<class T>
HashTableIterator<T>::HashTableIterator(std::vector<std::list<T>> &ht, bool end) :
		hashTable(ht) {
	// last element of last row
	int endRow = ht.size - 1;
	int endCol = ht.at[endRow].size + 1; // this represents ONE past the end of the data
	this->endPosition = coords { endRow, endCol };

	if (end) {
		this->position = this->endPosition;
	} else {
		// beginning
		this->position = coords { 0, 0 };
	}

}

template<class T>
T& HashTableIterator<T>::operator*() {
	// get row
	auto row = this->hashTable.at(this->position.row);

	// now, find column... it's clumsy, but std::list cannot be accessed by idx
	int count = 0;
	for (auto item : row) {
		if (count == this->position.column) {
			return item;
		}
		++count;
	}

	// this really shouldn't throw an error, but...
	throw std::out_of_range("You've gone too far this time.");
}

template<class T>
HashTableIterator<T>& HashTableIterator<T>::operator++() {

	// so, we want to find the next good item...
	T item;
	bool found;
	while(!found && position != endPosition) {
		bool columnAtEndOfRow = position.column == (hashTable.at(position.row).size - 1);
		bool noMoreRows = position.row == (hashTable.size - 1);
		bool notAtEndOfCurrentRow = position.column < hashTable.at(position.row).size;

		if (columnAtEndOfRow && noMoreRows) {
			// if end of row and no more rows, set endPosition
			position = this->endPosition;
		} else if (columnAtEndOfRow /* and more rows exist */) {
			// if at end of row, move to next and reset column idx
			position = coords { position.row, 0 };
			continue;
		} else if (notAtEndOfCurrentRow) {
			// happy path... get next column item in list
			position = coords { position.row, position.column++ };
		} else {
			// this really shouldn't throw an error, but...
			throw std::out_of_range("You've gone too far this time.");
		}
	}

	return this;
}

template<class T>
bool HashTableIterator<T>::operator!=(const HashTableIterator<T> &it) const {
	// just compare the positions
	return this->position != it.position;
}

#endif /* SRC_HASHTABLEITERATOR_H_ */
