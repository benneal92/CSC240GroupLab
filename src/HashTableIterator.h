/*
 * HashTableIterator.h
 *
 *  Created on: May 5, 2021
 *      Author: Ben
 *
 *
 *  Warning: this has no testing behind it yet. Beware!
 *
 *  Using 'long long unsigned int' in this file so it compares cleanly to the std::{vector, list}.size() returns.
 */

#ifndef SRC_HASHTABLEITERATOR_H_
#define SRC_HASHTABLEITERATOR_H_

#include <utility>
#include <vector>
#include <list>
#include <stdexcept>

template<class T>
class HashTableIterator {

	class coords {
	public:
		long long unsigned int row;
		long long unsigned int column;

		bool operator==(const coords &incoming) const {
			return (this->row == incoming.row)
					&& (this->column == incoming.column);
		}
		bool operator!=(const coords &incoming) const {
			return !(*this == incoming);
		}
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
	T heldItem;
};

template<class T>
HashTableIterator<T>::HashTableIterator(std::vector<std::list<T>> &ht, bool end) :
		hashTable(ht) {
	// last element of last row
	long long unsigned int endRow = ht.size() - 1;
	long long unsigned int endCol = ht.at(endRow).size() + 1; // this represents ONE past the end of the data
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
	long long unsigned int count = 0;
	for (auto item : row) {
		if (count == this->position.column) {
			this->heldItem = item;
			return this->heldItem;
		}
		++count;
	}

	// this really shouldn't throw an error, but...
	throw std::out_of_range("You've gone too far this time.");
}

template<class T>
HashTableIterator<T>& HashTableIterator<T>::operator++() {
	auto isValid = [&](coords position) {
		if (position.row >= hashTable.size()) {
			return false;
		}
		std::list<T> row = hashTable.at(position.row);
		// not empty at the row and column is within bounds
		return !row.empty() && position.column < row.size();
	};

	// so, we want to find the next good item...
	// increment one step to start
	position.column++;
	while (!isValid(position)) {
		bool columnAtEndOfRow;
		bool noMoreRows;
		bool notAtEndOfCurrentRow;
		bool rowEmpty;

		try {
			columnAtEndOfRow = position.column
					>= (hashTable.at(position.row).size());
			noMoreRows = position.row == (hashTable.size());
			notAtEndOfCurrentRow = position.column
					< hashTable.at(position.row).size();
			rowEmpty = hashTable.at(position.row).empty();
		} catch (std::exception const& e) {
			// if ANY error while assigning these, return end position
			position = this->endPosition;
			break;
		}

		if ((rowEmpty || columnAtEndOfRow) && noMoreRows) {
			// if end of row and no more rows, set endPosition
			position = this->endPosition;
//			break;
		} else if (rowEmpty || columnAtEndOfRow /* and more rows exist */) {
			// if at end of row, move to next and reset column idx
			position = coords { position.row + 1, 0 };
		} else if (notAtEndOfCurrentRow) {
			// happy path... get next column item in list
			position = coords { position.row, position.column + 1 };
		} else {
			// this really shouldn't throw an error, but...
			throw std::out_of_range("You've gone too far this time.");
		}
	}

	return *this;
}

template<class T>
bool HashTableIterator<T>::operator!=(const HashTableIterator<T> &it) const {
	// just compare the positions
	return position != it.position;
}

#endif /* SRC_HASHTABLEITERATOR_H_ */
