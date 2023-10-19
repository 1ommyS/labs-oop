#pragma once

#include <ostream>
#include "BaseFigure.hpp"
#include "vector.hpp"

class Pentagon : public BaseFigure {

public:
    explicit Pentagon(Vector <Point> points);

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon);

    [[nodiscard]] Point CalculateCenter() const override;

    double CalculateArea() const override;

    static Pentagon CreateInstance(Vector <Point> points) {
        return Pentagon(points);
    }
};


