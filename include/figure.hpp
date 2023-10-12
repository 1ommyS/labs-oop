#pragma once;

#include <iostream>
#include "vector.hpp"

using std::pair;

class Figure {
  protected:
   Vector<pair<double, double>> points;

  public:
   Figure() = default;

   Figure(const Vector<pair<double, double>>& points);
};