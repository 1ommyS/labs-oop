#pragma once

#include "IFigureValidator.h"
#include "Pentagon.h"

class PentagonValidator : public IFigureValidator {
  public:
   void Validate(Vector<Point> points) override {
      if (points.size() != 4) {
         throw std::invalid_argument("Invalid number of points");
      }
      Vector<double> distances;
      for (int i = 0; i < 5; i++) {
         for (int j = i + 1; j < 5; j++) {
            double distance = std::sqrt(std::pow(points[i].x - points[j].x, 2) +
                                        std::pow(points[i].y - points[j].y, 2));
            distances.push_back(distance);
         }
      }

      // Check if the distances are equal for all sides
      double sideLength = distances[0];
      for (int i = 1; i < 10; i++) {
         if (distances[i] != sideLength) {
            throw std::invalid_argument(
                "Введенные точки не образуют пятиугольник");
         }
      }
   }

   bool IsAllowedFor(const std::type_info &type) override {
      return typeid(Pentagon) == type;
   }
};
