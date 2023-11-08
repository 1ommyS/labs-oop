#include "SixValidator.h"
#include "Figure.h"
#include "Six.h"

const int AMOUNT_OF_POINTS = 6;
const double EPS = 1e-9;

template <class T>
bool SixValidator<T>::isAllowed(const Figure<T>& fugure) const {
   try {
      dynamic_cast<const Trap<T>&>(fugure);
   } catch (const std::bad_cast& e) {
      return false;
   }
   return true;
}

template <class T>
void SixValidator<T>::validate(const Figure<T>& figure) const {
   for (int i = 0; i < 6; i++) {
      if (abs(figure.getPoints().get()[(i + 1) % AMOUNT_OF_POINTS] -
              figure.getPoints().get()[i]) <= EPS) {
         throw std::invalid_argument("The side with 0 length found(");
      }
   }

   for (int i = 0; i < 6; i++) {
      if (isParalel(figure.getPoints().get()[(i + 1) % AMOUNT_OF_POINTS] -
                        figure.getPoints().get()[i],
                    figure.getPoints().get()[(i + 2) % AMOUNT_OF_POINTS] -
                        figure.getPoints().get()[(i + 1) % AMOUNT_OF_POINTS])) {
         throw std::invalid_argument("neighbor sides are parallel");
      }
   }

   if (!isParalel(figure.getPoints().get()[0] - figure.getPoints().get()[1],
                  figure.getPoints().get()[3] - figure.getPoints().get()[4])) {
      throw std::invalid_argument("opposite sides arent paralell");
   }
}
