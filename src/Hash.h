#ifndef HASH_H
#define HASH_H

#include <cstddef> 

template<typename T>
class Hash {
public:
    size_t operator()(const T&);

};

#endif /* HASH_H */