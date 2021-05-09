#ifndef SRC_HASHTABLEITERATOR_H_
#define SRC_HASHTABLEITERATOR_H_

/*
 * HashTableIterator.h
 *
 *  Created on: May 5, 2021
 *      Author: Benjamin Liden
 */

#include <utility>
#include <vector>
#include <list>
#include <stdexcept>

class coords {
public:
	long long unsigned int row;			/* Using 'long long unsigned int' in this file so it compares */
	long long unsigned int column;		/* cleanly to the std::{vector, list}.size() returns. */

	bool operator==(const coords &incoming) const {
		return (this->row == incoming.row) && (this->column == incoming.column);
	}
	bool operator!=(const coords &incoming) const {
		return !(*this == incoming);
	}
};

template<class T>
class HashTableIterator {

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

	bool isValidPosition() const;
	coords getNextPosition(coords const &position) const;
	void seekNextValidPosition();
};

template<class T>
HashTableIterator<T>::HashTableIterator(std::vector<std::list<T>> &ht, bool end) :
		hashTable(ht) {
	// last element of last row
	long long unsigned int endRow = ht.size() - 1; // last good row
	long long unsigned int endCol = ht.at(endRow).size() + 1; // this represents ONE past the end of the data
	this->endPosition = coords { endRow, endCol };

	if (end) {
		this->position = this->endPosition;
	} else {
		// start at beginning
		this->position = coords { 0, 0 };
		// then use that or next good coordinate
		this->seekNextValidPosition();
	}

}

/*
 * Pre: The iterator is initialized and points to a valid position.
 * Post: The item at the iterator's position will be returned.
 * Data Members: hashTable, position, heldItem
 * Member Functions: n/a
 */
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

/*
 * Pre: The iterator is initialized.
 * Post: The iterator's position will be updated to the next _valid_ item.
 * Data Members: position
 * Member Functions: n/a
 */
template<class T>
HashTableIterator<T>& HashTableIterator<T>::operator++() {
	// increment one step to start
	this->position.column++;
	// then find the next good item if that
	this->seekNextValidPosition();
	return *this;
}


template<class T>
bool HashTableIterator<T>::operator!=(const HashTableIterator<T> &it) const {
	// just compare the positions
	return this->position != it.position;
}

/*
 * Is the given position valid and occupied?
 *
 * Pre: The iterator is initialized.
 * Post: The iterator's current position will be checked for validity and return a boolean.
 * Data Members: hashTable, position
 * Member Functions: n/a
 */
template<class T>
bool HashTableIterator<T>::isValidPosition() const {
	if (this->position.row >= hashTable.size()) {
		return false;
	}
	std::list<T> row = hashTable.at(this->position.row);
	// not empty at the row and column is within bounds
	return !row.empty() && this->position.column < row.size();
}

/*
 * Advance this->position to the next immediate step, regardless of validity.
 *
 * Pre: The iterator is initialized.
 * Post: The iterator's current position will be moved to the next immediate slot.
 * Data Members: hashTable, position, endPosition
 * Member Functions: n/a
 */
template<class T>
coords HashTableIterator<T>::getNextPosition(coords const &position) const {
	bool columnAtEndOfRow;
	bool lastRow;
	bool notAtEndOfCurrentRow;
	bool rowEmpty;

	try {
		columnAtEndOfRow = position.column
				>= (hashTable.at(position.row).size());
		lastRow = position.row == (hashTable.size() - 1);
		notAtEndOfCurrentRow = position.column
				< hashTable.at(position.row).size();
		rowEmpty = hashTable.at(position.row).empty();
	} catch (std::exception const &e) {
		// if ANY error while assigning these, return end position
		return this->endPosition;
	}

	if ((rowEmpty || columnAtEndOfRow) && lastRow) {
		// if end of row and no more rows, set endPosition
		return this->endPosition;
	} else if (rowEmpty || columnAtEndOfRow /* and more rows exist */) {
		// if at end of row, move to next and reset column idx
		return coords { position.row + 1, 0 };
	} else if (notAtEndOfCurrentRow) {
		// happy path :) get next column item in list
		return coords { position.row, position.column + 1 };
	} else {
		// this really shouldn't throw an error, but...
		throw std::out_of_range("You've gone too far this time.");
	}
}

/*
 * Move current coords to next VALID position, inclusive of current position.
 *
 * Pre: The iterator is initialized.
 * Post: The iterator's current position will be moved to the _valid_ slot.
 * Data Members: position, endPosition
 * Member Functions: getNextPosition, isValidPosition
 */
template<class T>
void HashTableIterator<T>::seekNextValidPosition() {
	while (!isValidPosition()
			&& this->position != this->endPosition) {
		this->position = this->getNextPosition(this->position);
	}
}

#endif /* SRC_HASHTABLEITERATOR_H_ */
