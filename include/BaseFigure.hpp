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

    virtual explicit operator double() const = 0;

    ~BaseFigure() = default;
};