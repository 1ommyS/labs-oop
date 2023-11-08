#pragma once
#include <memory>
#include <vector>
#include "Figure.h"
#include "NumberConcept.h"
template <Number T>
class FigureList {
  private:
   int size;
   int capacity;
   T* figures;

  public:
   FigureList();
   ~FigureList();
   void resize();
   void push_back(T figure);
   void remove(int index);
   int getSize() const;
   T operator[](const int index) const;
};