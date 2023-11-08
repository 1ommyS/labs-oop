#include "PentagonValidator.h"
#include "Figure.h"
#include "Pentagon.h"

const int AMOUNT_OF_POINTS = 5;
const double EPS = 1e-9;

template <class T>
bool PentagonValidator<T>::isAllowed(const Figure<T>& fugure) const {
   try {
      dynamic_cast<const Pentagon<T>&>(fugure);
   } catch (const std::bad_cast& e) {
      return false;
   }
   return true;
}

template <class T>
void PentagonValidator<T>::validate(const Figure<T>& figure) const {
   for (int i = 0; i < 5; i++) {
      if (abs(figure.getPoints().get()[(i + 1) % AMOUNT_OF_POINTS] -
              figure.getPoints().get()[i]) <= EPS) {
         throw std::invalid_argument("The side with 0 length found(");
      }
   }

   for (int i = 0; i < 5; i++) {
      if (isParalel(figure.getPoints().get()[(i + 1) % AMOUNT_OF_POINTS] -
                        figure.getPoints().get()[i],
                    figure.getPoints().get()[(i + 2) % AMOUNT_OF_POINTS] -
                        figure.getPoints().get()[(i + 1) % AMOUNT_OF_POINTS])) {
         throw std::invalid_argument("neighbor sides are parallel");
      }
   }
}
