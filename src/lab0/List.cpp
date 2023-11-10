#include "List.h"
#include <memory>
#include "Figure.h"
#include "NumberConcept.h"

template <Figure T>
List<T>::List() {
   this->size = 0;
   this->capacity = 10;

   this->figures = new T[this->capacity];
}

template <Figure T>
List<T>::~List() {
   this->size = 0;
   this->capacity = 0;
}

template <Figure T>
void List<T>::push_back(T figure) {
   if (size + 1 > capacity) resize();
   figures[size++] = figure;
}

template <Figure T>
void List<T>::resize() {
   capacity *= 2;
   T* newFigures = new T[this->capacity];
   for (int i = 0; i < size; ++i) {
      newFigures[i] = figures[i];
   }
   figures = newFigures;
}

template <Figure T>
T List<T>::operator[](const int index) const {
   if (index >= size || index < 0) {
      throw std::invalid_argument("Invalid index");
   }
   return figures[index];
}

template <Figure T>
void List<T>::remove(int index) {
   if (index >= size || index < 0) {
      throw std::invalid_argument("Invalid index");
   }
   for (int i = index; i < size; ++i) {
      figures[i] = figures[i + 1];
   }
   size--;
}

template <Figure T>
int List<T>::getSize() const {
   return size;
}
