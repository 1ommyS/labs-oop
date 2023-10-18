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
   auto first_vector = pair<double, double>(points[1].first - points[0].first,
                                  points[1].second - points[1].second);
   auto second_vector = pair<double, double>(points[3].first - points[2].first,
                                  points[3].second - points[2].second);

   if (!((first_vector.first == 0 && first_vector.second == 0 && second_vector.first == 0 && second_vector.second == 0) ||
         (first_vector.first * second_vector.second == first_vector.second * second_vector.first))) {
      throw std::invalid_argument("Векторы не коллинеарны");
   }
}