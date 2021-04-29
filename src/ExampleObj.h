#ifndef EXAMPLEOBJ_H
#define EXAMPLEOBJ_H

#include <string>
#include <cstddef> // size_t

#include "Hash.h" // functor

/**
 * Only an example
 * 
 * This class can be separated out into source and header 
 */
class ExampleObj {
public:
    ExampleObj(std::string str)
    : str{str}
    { }

    std::string str;

};

/**
 * define the functor for ExampleObj
 */ 
template<>
class Hash<ExampleObj> {
public:
    size_t operator()(const ExampleObj& obj) {
        size_t hashVal = 0;

        for(auto e : obj.str)
            hashVal = 37 * hashVal + e;

        return hashVal;    
    }
};

#endif /* EXAMPLEOBJ_H */
