#pragma once

#include <iostream>
#include "vector.hpp"

struct Point {
   double x;
   double y;

   Point(int x, int y) : x(x), y(y) {}
};

class BaseFigure {
  public:
   BaseFigure() = default;

   virtual Point CalculateCenter() const;
   virtual double CalculateArea() const;
   virtual Vector<Point> GetPoints();

   virtual BaseFigure &operator=(BaseFigure &other);
   virtual BaseFigure &operator=(BaseFigure &&other);
   virtual bool operator==(BaseFigure &other);

   ~BaseFigure() = default;
};