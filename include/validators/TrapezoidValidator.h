//
// Created by Ivan on 12.10.2023.
//

#ifndef LAB0_FIGUREVALIDATOR_H
#define LAB0_FIGUREVALIDATOR_H

#include "IFigureValidator.h"

class TrapezoidValidator : public IFigureValidator {
  public:
   void Validate(Vector<pair<double, double>> points) override;
};

#endif  // LAB0_FIGUREVALIDATOR_H
