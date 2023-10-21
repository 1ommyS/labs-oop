//
// Created by Ivan on 12.10.2023.
//

#pragma once

#include <iostream>
#include <ostream>
#include <utility>
#include "BaseFigure.hpp"
#include "FigureValidator.h"
#include "vector.hpp"

class Trapezoid : public BaseFigure {
  protected:
   Vector<Point> _points;

  public:
   Trapezoid() = default;
   explicit Trapezoid(Vector<Point> &points) { _points = points; }

   friend std::ostream &operator<<(std::ostream &os,
                                   const Trapezoid &trapezoid) {
      for (int i = 0; i < trapezoid._points.size(); i++) {
         os << "(" << trapezoid._points[i].x << "," << trapezoid._points[i].y
            << ")";
      }
      return os;
   }

   Vector<Point> GetPoints() { return _points; }

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

      if (typeid(Pentagon) != typeid(other)) {
         return false;
      }

      return _points == other.GetPoints();
   }
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
      // Расчет площади трапеции
      double base1 = std::abs(_points[1].x - _points[0].x);
      double base2 = std::abs(_points[3].x - _points[2].x);
      double height = std::abs(_points[0].y - _points[2].y);

      double area = (base1 + base2) * height / 2.0;

      return area;
   }

   static Trapezoid CreateInstance(Vector<Point> &points) {
      FigureValidator::Validate(typeid(Trapezoid), points);

      return Trapezoid(points);
   }
};
