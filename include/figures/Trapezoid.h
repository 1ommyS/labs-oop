//
// Created by Ivan on 12.10.2023.
//

#ifndef LAB0_TRAPEZOID_H
#define LAB0_TRAPEZOID_H

#include <ostream>
#include "BaseFigure.hpp"

class Trapezoid : public BaseFigure {
public:
    explicit Trapezoid(Vector<std::pair<double, double>> points);

    friend std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid);

    [[nodiscard]] pair<double, double> CalculateCenter() const override;

    explicit operator double() const override;

};


#endif //LAB0_TRAPEZOID_H
