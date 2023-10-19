#pragma once

#include "Rombus.h"
#include "IFigureValidator.h"

class RombusValidator : public IFigureValidator {
public:
    void Validate(const std::type_info &type, Vector<Point> points) {
        if (points.size() != 4) {
            throw std::invalid_argument("Invalid number of points");
        }
        Vector<double> distances;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                double distance = std::sqrt(std::pow(points[i].x - points[j].x, 2) +
                                            std::pow(points[i].y - points[j].y, 2));
                distances.push_back(distance);
            }
        }

        // Check if the distances are equal for opposite sides and diagonals
        if (!(distances[0] == distances[2] && distances[1] == distances[3] &&
              distances[0] == distances[1])) {
            throw std::invalid_argument("Введенные точки не образуют ромб");
        }
    }

    bool IsAllowedFor(const std::type_info &type) {
        return typeid(Rombus) == type;
    }
};
