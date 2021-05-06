/*
 * HashTableIterator.h
 *
 *  Created on: May 5, 2021
 *      Author: Ben
 *
 *
 *  This thing needs some work
 */

#ifndef SRC_HASHTABLEITERATOR_H_
#define SRC_HASHTABLEITERATOR_H_

template<class T>
class HashTableIterator {
	HashTableIterator(/* something */);
	T& operator*();
	HashTableIterator<T>& operator++();
	bool operator!=(const HashTableIterator<T>& it) const;
};

#endif /* SRC_HASHTABLEITERATOR_H_ */
