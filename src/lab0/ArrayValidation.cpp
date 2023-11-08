#include "ArrayValidation.h"
#include "Point.h"

template <typename T>
bool validate(const std::shared_ptr<Point<T>> points1,
              const std::shared_ptr<Point<T>> points2, const int size) {
   for (int i = 0; i < size; ++i) {
      if (points1.get()[i] != points2.get()[i]) {
         return false;
      }
   }
   return true;
}
