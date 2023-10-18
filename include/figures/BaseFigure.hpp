#pragma once;

#include <iostream>
#include "vector.hpp"

using std::pair;

class BaseFigure {
  protected:
   Vector<pair<double, double>> _points;

  public:
   BaseFigure() = default;

   virtual pair<double, double> CalculateCenter() const;

   virtual explicit operator double() const = 0;

   virtual ~BaseFigure();

   static BaseFigure CreateInstance(Vector<pair<double, double>>);

   friend std::ostream &operator<<(std::ostream &os, const BaseFigure &figure);

   friend std::istream &operator>>(std::istream &is, BaseFigure &figure);

   static BaseFigure CreateInstance(Vector<pair<double, double>>);
};