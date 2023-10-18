//
// Created by Ivan on 12.10.2023.
//

#ifndef LAB0_IFIGUREVALIDATOR_H
#define LAB0_IFIGUREVALIDATOR_H

#include "figures/BaseFigure.hpp"

using std::pair;

class IFigureValidator {
protected:
    Vector<IFigureValidator> _validators;
public:
    virtual void Validate(Vector <pair<double, double>> points) = 0;
};

#endif  // LAB0_IFIGUREVALIDATOR_H