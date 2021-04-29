#ifndef HASH_H
#define HASH_H

#include <cstddef> // size_t

/**
 * Hash functor to be defined individually for each obj
 */ 
template<typename T>
class Hash {
public:
    size_t operator()(const T&);

};

#endif /* HASH_H */