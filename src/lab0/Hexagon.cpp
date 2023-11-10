#include "Hexagon.h"
#include <iostream>
#include "Point.h"

template <Number T>
Hexagon<T>::Hexagon() {
   this->figureName = "Hexagon";
   this->points = std::make_shared<Point<T>>(4);
}
template <Number T>
Hexagon<T> Hexagon<T>::create(const std::shared_ptr<Point<T>> points) {
   return Hexagon<T>{points};
}

template <Number T>
Hexagon<T>::Hexagon(const std::shared_ptr<Point<T>> points) {
   this->figureName = "Hexagon";
   this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
   for (int i = 0; i < 4; ++i) {
      this->points.get()[i] = points.get()[i];
   }

   ValidationCompositor<T> validator;
   validator.validate(dynamic_cast<Figure<T>&>(*this));
}

template <Number T>
Hexagon<T>::Hexagon(const Hexagon<T>& other) {
   this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
   for (int i = 0; i < 4; ++i) {
      this->points.get()[i] = other.points.get()[i];
   }
}

template <Number T>
Hexagon<T>::Hexagon(Hexagon<T>&& other) {
   this->points = other.points;

   // delete[] other.points;
   // other.points = nullptr;
}

template <Number T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& other) {
   this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
   for (int i = 0; i < 4; ++i) {
      this->points.get()[i] = other.points.get()[i];
   }
   return *this;
}

template <Number T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other) {
   this->points = other.points;

   // delete[] other.points;
   // other.points = nullptr;

   return *this;
}

template <Number T>
bool Hexagon<T>::operator==(const Hexagon<T>& other) const {
   for (int i = 0; i < 4; ++i) {
      int flag = 0;
      for (int j = 0; j < 4; ++j) {
         if ((this->points.get()[i].getX() == other.points.get()[i].getX()) &&
             (this->points.get()[i].getY() == other.points.get()[i].getY())) {
            flag = 1;
         }
      }
      if (!flag) {
         return false;
      }
   }
   return true;
}

// bool Hexagon::operator==(const Figure& other){
//     for (int i = 0; i < 4; ++i){
//         if (!(points[i] == other.getPoints()[i])){
//             return false;
//         }
//     }
//     return true;
// }
template <Number T>
Figure<T>& Hexagon<T>::operator=(const Figure<T>&& other) {
   try {
      const Hexagon<T>&& other_trap = dynamic_cast<const Hexagon<T>&&>(other);
      return *this = other_trap;
   } catch (const std::bad_cast& e) {
      throw std::invalid_argument("exepted Hexagon");
   }
}
template <Number T>
Figure<T>& Hexagon<T>::operator=(const Figure<T>& other) {
   try {
      const Hexagon<T>& other_trap = dynamic_cast<const Hexagon<T>&>(other);
      return *this = other_trap;
   } catch (const std::bad_cast& e) {
      throw std::invalid_argument("exepted Hexagon");
   }
}

template <Number T>
bool Hexagon<T>::operator==(const Figure<T>& other) {
   try {
      const Hexagon<T>& other_trap = dynamic_cast<const Hexagon<T>&>(other);
      return *this == other_trap;
   } catch (const std::bad_cast& e) {
      return false;
   }
}

// std::string Hexagon::getFigureName() const{
//     return figureName;
// }

// Point* Hexagon::getPoints() const{
//     return points;
// }

template <Number T>
Point<T> Hexagon<T>::center() const {
   T Xsum = 0;
   T Ysum = 0;
   for (int i = 0; i < 4; ++i) {
      Xsum += this->points.get()[i].getX();
      Ysum += this->points.get()[i].getY();
   }
   Point<T> center;
   center.setX(Xsum / 4);
   center.setY(Ysum / 4);

   return center;
}

template <Number T>
Hexagon<T>::operator double() const {
   T s = 0;
   for (int i = 0; i < 4; i++) {
      s +=
          this->points.get()[i].getX() *
              this->points.get()[(i + 1) % 4].getY() -
          this->points.get()[i].getY() * this->points.get()[(i + 1) % 4].getX();
   }
   return fabs(s / 2);
}

template <Number T>
void Hexagon<T>::fillPoints(const int pointsAmount, Point<T>* res,
                            const Point<T>* data) {
   for (int i = 0; i < pointsAmount; ++i) {
      res[i] = data[i];
   }
}

template <Number T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& figure) {
   return figure.print(std::cout);
}

template <Number T>
std::istream& operator>>(std::istream& is, Hexagon<T>& figure) {
   return figure.read(std::cin);
}
