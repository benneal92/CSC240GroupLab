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

struct A {
    std::string name;

    //==
};

template<>
class Hash<A> {
public:
    size_t operator()(const A& a){
        size_t hashVal = 0;
        for( char ch : a.name )
        hashVal = 37 * hashVal + ch;
        return hashVal;
    }
};




#endif /* HASH_H */