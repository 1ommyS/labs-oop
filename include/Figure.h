#pragma once
#include <concepts>
#include <memory>
#include <string>
#include "NumberConcept.h"
#include "Point.h"

template <Number T>
class Figure {
   template <Number U>
   friend std::ostream& operator<<(std::ostream& os, const Figure<U>& figure);
   template <Number U>
   friend std::istream& operator>>(std::istream& is, Figure<U>& figure);

  protected:
   Figure();
   Figure(std::string figureName);
   std::ostream& print(std::ostream& os) const = 0;

  public:
   virtual ~Figure();
   virtual operator double() const = 0;
   virtual Point<T> center() const = 0;
   virtual bool operator==(const Figure<T>& other) = 0;
   virtual Figure<T>& operator=(const Figure<T>&& other) = 0;
   virtual Figure<T>& operator=(const Figure<T>& other) = 0;
   virtual std::string getFigureName() const;
   virtual std::shared_ptr<Point<T>> getPoints() const;

  protected:
   std::string figureName;
   std::shared_ptr<Point<T>> points;
   virtual void fillPoints(const int pointsAmount, Point<T>* res,
                           const Point<T>* data) = 0;
};
template <Number T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure);
template <Number T>
std::istream& operator>>(std::istream& is, Figure<T>& figure);