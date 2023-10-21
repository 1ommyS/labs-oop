//
// Created by Ivan on 12.10.2023.
//

#ifndef LABS_OOP_IFIGUREVALIDATOR_H
#define LABS_OOP_IFIGUREVALIDATOR_H

#include "BaseFigure.hpp"
#include "vector.hpp"

class IFigureValidator {
  public:
//    void Validate(const std::type_info &type, Vector<Point> points);

   virtual void Validate(Vector<Point> points);

   virtual bool IsAllowedFor(const std::type_info &type);
};

#endif  // LABS_OOP_IFIGUREVALIDATOR_H