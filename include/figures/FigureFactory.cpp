//
// Created by Ivan on 12.10.2023.
//

#include "FigureFactory.h"

#include "Trapezoid.h"

BaseFigure *FigureFactory::createTrapezoid(Vector<pair<double, double>> &points) {
    return new Trapezoid(points);
}
