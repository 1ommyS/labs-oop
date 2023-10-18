//
// Created by Ivan on 12.10.2023.
//

#include "figures/Trapezoid.h"
#include <iostream>

std::pair<double, double> Trapezoid::CalculateCenter() const {
   return BaseFigure::CalculateCenter();
}

std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid) {
   os << static_cast<const BaseFigure &>(trapezoid);
   return os;
}

Trapezoid::operator double() const { return 0; }

Trapezoid::Trapezoid(Vector<std::pair<double, double>> points) {
   _points = points;
}
static Trapezoid CreateInstance(Vector<pair<double, double>> points) {
   return Trapezoid(points);
}
