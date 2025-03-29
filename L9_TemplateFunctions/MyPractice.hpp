//MY EXERCISEEEE
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// Template class declaration
template <typename T>
class Vector {
public:
    T at(size_t i);
};

// Include the implementation at the bottom
#include "L9_TemplateFunctions.cpp"  // This forces the compiler to see the implementation

#endif
