//
// Created by Ivan on 12.10.2023.
//

#ifndef LAB0_FIGUREFACTORY_H
#define LAB0_FIGUREFACTORY_H


#include "BaseFigure.hpp"
#include "vector.hpp"

class FigureFactory {
public:
    static BaseFigure *createTrapezoid(Vector<pair<double, double>>& points);
};


#endif //LAB0_FIGUREFACTORY_H
