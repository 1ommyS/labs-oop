//
// Created by Ivan on 12.10.2023.
//

#pragma once

#include <ostream>
#include "BaseFigure.hpp"
#include "FigureValidator.h"
#include "vector.hpp"

class Rombus : public BaseFigure {
  protected:
   Vector<Point> _points;

  public:
   explicit Rombus(Vector<Point> &points) { _points = points; }

   friend std::ostream &operator<<(std::ostream &os, const Rombus &rombus) {
      for (int i = 0; i < rombus._points.size(); i++) {
         os << "(" << rombus._points[i].x << "," << rombus._points[i].y << ")";
      }
      return os;
   }

   Vector<Point> GetPoints() { return _points; }

   Point CalculateCenter() const override {
      double xSum = 0.0;
      double ySum = 0.0;

      // Суммируем координаты всех вершин
      for (size_t i = 0; i < _points.size(); i++) {
         Point point = _points[i];

         xSum += point.x;
         ySum += point.y;
      }

      // Вычисляем среднее значение координат
      double centerX = xSum / _points.size();
      double centerY = ySum / _points.size();

      // Создаем новую точку, представляющую центр трапеции
      auto *center = new Point(centerX, centerY);
      return *center;
   }

   double CalculateArea() const override {
      // Calculate the lengths of the diagonals
      double d1 = std::sqrt(std::pow(_points[0].x - _points[2].x, 2) +
                            std::pow(_points[0].y - _points[2].y, 2));
      double d2 = std::sqrt(std::pow(_points[1].x - _points[3].x, 2) +
                            std::pow(_points[1].y - _points[3].y, 2));

      // Calculate the area using the formula
      double area = (d1 * d2) / 2;

      return area;
   }

   BaseFigure &operator=(BaseFigure &other) override {
      _points = other.GetPoints();
      return *this;
   }

   BaseFigure &operator=(BaseFigure &&other) override {
      _points = std::move(other.GetPoints());
      return *this;
   };
   bool operator==(BaseFigure &other) override {
      if (*this == other) {
         return true;
      }

      if (typeid(Rombus) != typeid(other)) {
         return false;
      }

      return _points == other.GetPoints();
   }

   static Rombus CreateInstance(Vector<Point> &points) {
      FigureValidator::Validate(typeid(Rombus), points);

      return Rombus(points);
   }
};
