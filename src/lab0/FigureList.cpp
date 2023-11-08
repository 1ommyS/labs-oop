#include "FigureList.h"
#include <memory>
#include "Figure.h"
#include "NumberConcept.h"

template <Number T>
FigureList<T>::FigureList() {
   this->size = 0;
   this->capacity = 10;

   this->figures = new T[this->capacity];
}

template <Number T>
FigureList<T>::~FigureList() {
   this->size = 0;
   this->capacity = 0;
}

template <Number T>
void FigureList<T>::push_back(T figure) {
   if (size + 1 > capacity) resize();
   figures[size++] = figure;
}

template <Number T>
void FigureList<T>::resize() {
   capacity *= 2;
   T* newFigures = new T[this->capacity];
   for (int i = 0; i < size; ++i) {
      newFigures[i] = figures[i];
   }
   figures = newFigures;
}

template <Number T>
T FigureList<T>::operator[](const int index) const {
   if (index >= size || index < 0) {
      throw std::invalid_argument("Invalid index");
   }
   return figures[index];
}

template <Number T>
void FigureList<T>::remove(int index) {
   if (index >= size || index < 0) {
      throw std::invalid_argument("Invalid index");
   }
   for (int i = index; i < size; ++i) {
      figures[i] = figures[i + 1];
   }
   size--;
}

template <Number T>
int FigureList<T>::getSize() const {
   return size;
}
