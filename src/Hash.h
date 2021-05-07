#ifndef HASH_H
#define HASH_H

#include <cstddef> 
#include <cmath>

template<typename T>
class Hash {
public:
	size_t operator()(const T&);
};

template<>
class Hash<int> {
public:
	size_t operator()(const int &n) {
		// Knuth's multiplicative method: https://stackoverflow.com/a/665545
		return (n * 2654435761) % (int)std::pow(2, 32);
	}
};

#endif /* HASH_H */
