//
// Created by Ivan on 12.10.2023.
//

#pragma once

#include "BaseFigure.hpp"
#include "vector.hpp"


class IFigureValidator {
public:
    void Validate(const std::type_info &type, Vector<Point> points);

    void Validate(Vector<Point> points);

    bool IsAllowedFor(const std::type_info &type);
};

