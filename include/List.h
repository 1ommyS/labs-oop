#pragma once
#include <memory>
#include <vector>
#include "Figure.h"
#include "FigureConcept.h"
template <Figure T>
class List {
  private:
   int size;
   int capacity;
   T* figures;

  public:
   List();
   ~List();
   void resize();
   void push_back(T figure);
   void remove(int index);
   int getSize() const;
   T operator[](const int index) const;
};