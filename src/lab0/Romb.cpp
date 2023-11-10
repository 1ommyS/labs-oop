#include "Romb.h"
#include "Figure.h"
#include "NumberConcept.h"
#include "Point.h"
#include "ValidationCompositor.cpp"
#include "ValidationCompositor.h"

template <Number T>
Romb<T>::Romb() {
   this->points = std::shared_ptr<Point<T>>(new Point<T>[points.get().size()]);
   this->figureName = "Romb";
}

template <Number T>
Romb<T>::Romb(const std::shared_ptr<Point<T>> points) {
   this->points = std::shared_ptr<Point<T>>(new Point<T>[points.get().size()]);
   this->figureName = "Romb";
   for (int i = 0; i < points.get().size(); ++i) {
      this->points.get()[i] = points.get()[i];
   }

   ValidationCompositor<T> validator;
   validator.validate(dynamic_cast<Figure<T>&>(*this));
   // fillPoints(points.get().size(), this->points, points);
}

template <Number T>
Romb<T>::Romb(const Romb<T>& other) {
   this->points = std::shared_ptr<Point<T>>(new Point<T>[points.get().size()]);
   for (int i = 0; i < points.get().size(); ++i) {
      this->points[i] = other.points[i];
   }
}

template <Number T>
Romb<T>::Romb(Romb<T>&& other) {
   this->points = other.points;
}

template <Number T>
Point<T> Romb<T>::center() const {
   T Xsum = 0;
   T Ysum = 0;
   for (int i = 0; i < points.get().size(); ++i) {
      Xsum += this->points.get()[i].getX();
      Ysum += this->points.get()[i].getY();
   }
   Point<T> center;
   center.setX(Xsum / points.get().size());
   center.setY(Ysum / points.get().size());

   return center;
}

template <Number T>
Romb<T>::operator double() const {
   double s = 0;
   for (int i = 0; i < points.get().size(); i++) {
      s += this->points.get()[i].getX() *
               this->points.get()[(i + 1) % points.get().size()].getY() -
           this->points.get()[i].getY() *
               this->points.get()[(i + 1) % points.get().size()].getX();
   }
   return fabs(s / 2);
}

template <Number T>
Romb<T>& Romb<T>::operator=(const Romb<T>& other) {
   this->points = std::shared_ptr<Point<T>>(new Point<T>[points.get().size()]);
   for (int i = 0; i < points.get().size(); ++i) {
      this->points.get()[i] = other.points.get()[i];
   }
   return *this;
}

template <Number T>
Romb<T>& Romb<T>::operator=(Romb<T>&& other) {
   this->points = other.points;
   return *this;
}

template <Number T>
bool Romb<T>::operator==(Romb<T>& other) {
   for (int i = 0; i < points.get().size(); ++i) {
      int flag = 0;
      for (int j = 0; j < points.get().size(); ++j) {
         if ((this->points[i].getX() == other.points[i].getX()) &&
             (this->points[i].getY() == other.points[i].getY())) {
            flag = 1;
         }
      }
      if (flag == 0) {
         return false;
      }
   }
   return true;
}

template <Number T>
void Romb<T>::fillPoints(const int pointsAmount, Point<T>* res,
                         const Point<T>* data) {
   for (int i = 0; i < points.get().size(); ++i) {
      res[i] = data[i];
   }
}

template <Number T>
std::ostream& operator<<(std::ostream& os, const Romb<T>& figure) {
   return figure.print(std::cout);
}
template <Number T>
std::istream& operator>>(std::istream& is, Romb<T>& figure) {
   return figure.read(std::cin);
}

template <Number T>
Figure<T>& Romb<T>::operator=(const Figure<T>&& other) {
   try {
      const Romb<T>&& other_romb = dynamic_cast<const Romb<T>&&>(other);
      return *this = other_romb;
   } catch (const std::bad_cast& e) {
      throw std::invalid_argument("exepted Romb");
   }
}
template <Number T>
Figure<T>& Romb<T>::operator=(const Figure<T>& other) {
   try {
      const Romb<T>& other_romb = dynamic_cast<const Romb<T>&>(other);
      return *this = other_romb;
   } catch (const std::bad_cast& e) {
      throw std::invalid_argument("exepted Romb");
   }
}

template <Number T>
bool Romb<T>::operator==(const Figure<T>& other) {
   try {
      const Romb<T>& other_romb = dynamic_cast<const Romb<T>&>(other);
      return *this == other_romb;
   } catch (const std::bad_cast& e) {
      return false;
   }
}
