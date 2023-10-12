//
// Created by Ivan on 12.10.2023.
//

#include "Trapezoid.h"

pair<double, double> Trapezoid::CalculateCenter() const {
    return BaseFigure::CalculateCenter();
}

std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid) {
    os << static_cast<const BaseFigure &>(trapezoid);
    return os;
}

Trapezoid::operator double() const {
    return 0;
}

Trapezoid::Trapezoid(Vector<std::pair<double, double>> points) {
    _points = points;
}
