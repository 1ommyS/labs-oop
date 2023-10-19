
#pragma once

#include "IFigureValidator.h"
#include "Trapezoid.h"

class TrapezoidValidator : public IFigureValidator {
public:
    /// @brief первый элемент вектора - точка в левом нижнем углу, второй - точка
    /// в
    /// правом нижнем углу, третий - точка в левом верхнем углу, четвертый -
    /// точка в правом верхнем углу
    /// @param points
    /// @throw std::invalid_argument
    void Validate(const std::type_info &type,
                  Vector<Point> points) {
        if (points.size() != 4) {
            throw std::invalid_argument("Invalid number of points");
        }
        auto first_vector =
                Point(points[1].x - points[0].x,
                      points[1].y - points[1].y);
        auto second_vector =
                Point(points[3].x - points[2].x,
                      points[3].y - points[2].y);

        if (!((first_vector.x == 0 && first_vector.y == 0 &&
               second_vector.x == 0 && second_vector.y == 0) ||
              (first_vector.x * second_vector.y ==
               first_vector.y * second_vector.x))) {
            throw std::invalid_argument("Векторы не коллинеарны");
        }
    }

    bool IsAllowedFor(const std::type_info &type) {
        return typeid(Trapezoid) == type;
    }
};


