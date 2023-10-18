//
// Created by Ivan on 18.10.2023.
//

#ifndef LABS_OOP_FIGUREVALIDATOR_H
#define LABS_OOP_FIGUREVALIDATOR_H

#include "IFigureValidator.h"

class FigureValidator : IFigureValidator {
private:
    Vector<IFigureValidator> _validators = {new TrapezoidValidator()};
};


#endif //LABS_OOP_FIGUREVALIDATOR_H
