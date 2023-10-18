//
// Created by Ivan on 12.10.2023.
//

#include "validators/TrapezoidValidator.h"

/// @brief первый элемент вектора - точка в левом нижнем углу, второй - точка в
/// правом нижнем углу, третий - точка в левом верхнем углу, четвертый - точка в
/// правом верхнем углу
/// @param points
/// @throw std::invalid_argument

void TrapezoidValidator::Validate(Vector<pair<double, double>> points) {
   if (points.size() != 4) {
      throw std::invalid_argument("Invalid number of points");
   }
   auto v1 = pair<double, double>(points[1].first - points[0].first,
                                  points[1].second - points[1].second);
   auto v2 = pair<double, double>(points[3].first - points[2].first,
                                  points[3].second - points[2].second);

   if (!((v1.first == 0 && v1.second == 0 && v2.first == 0 && v2.second == 0) ||
         (v1.first * v2.second == v1.second * v2.first))) {
      throw std::invalid_argument("Векторы неколлинеарны");
   }
}