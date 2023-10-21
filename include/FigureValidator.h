//
// Created by Ivan on 18.10.2023.
//

#ifndef LABS_OOP_FIGUREVALIDATOR_H
#define LABS_OOP_FIGUREVALIDATOR_H

#include "IFigureValidator.h"
#include "PentagonValidator.h"
#include "RombusValidator.h"
#include "TrapezoidValidator.h"
#include "vector.hpp"

class FigureValidator : IFigureValidator {
    static Vector<IFigureValidator> _validators;

public:
    static void Validate(const std::type_info &type, Vector<Point> points) {
        for (size_t i = 0; i < FigureValidator::_validators.size(); i++) {
            auto currentValidator = FigureValidator::_validators[i];

            if (currentValidator.IsAllowedFor(type)) {
                currentValidator.Validate(points);
            }
        }
    }

};


Vector<IFigureValidator> FigureValidator::_validators = {
        TrapezoidValidator(),
        RombusValidator(),
        PentagonValidator()
};

#endif  // LABS_OOP_FIGUREVALIDATOR_H
