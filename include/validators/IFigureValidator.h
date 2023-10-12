//
// Created by Ivan on 12.10.2023.
//

#ifndef LAB0_IFIGUREVALIDATOR_H
#define LAB0_IFIGUREVALIDATOR_H


#include "figures/BaseFigure.hpp"

class IFigureValidator {
    virtual void Validate(BaseFigure figure);

protected:
    Vector<IFigureValidator> validators;

};


#endif //LAB0_IFIGUREVALIDATOR_H