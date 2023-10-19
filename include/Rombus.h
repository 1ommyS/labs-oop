//
// Created by Ivan on 12.10.2023.
//

#pragma once

#include <ostream>
#include "BaseFigure.hpp"
#include "vector.hpp"

class Rombus : public BaseFigure {
public:
    explicit Rombus(Vector<Point> points);

    friend std::ostream &operator<<(std::ostream &os, const Rombus &rombus);

    Point CalculateCenter() const override;

    double CalculateArea() const override;

    static Rombus CreateInstance(Vector<Point> points) {
        return Rombus(points);
    }
};


