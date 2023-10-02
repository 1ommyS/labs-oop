#pragma once

#include "vector.h"

template<typename T>
class Vector {
private:

public:
 void push_back(T item);

 T pop_back();

 bool remove(T elem);

 Vector reverse();

 Vector reserve();

 int size(); 
 Vector resize(int new_capacity);

 int& operator[](int);
};
