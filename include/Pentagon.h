#pragma once

#include <ostream>
#include "./BaseFigure.hpp"
#include "./FigureValidator.h"
#include "vector.hpp"

class Pentagon : public BaseFigure {
  protected:
   Vector<Point> _points;

  public:
   explicit Pentagon(Vector<Point> points) { _points = points; }

   friend std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon) {
      for (int i = 0; i < pentagon._points.size(); i++) {
         os << "(" << pentagon._points[i].x << "," << pentagon._points[i].y
            << ")";
      }
      return os;
   }

   Vector<Point> GetPoints() { return _points; }

   [[nodiscard]] Point CalculateCenter() const override {
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

   double CalculateArea() const override {
      // Разбиваем пятиугольник на треугольники
      // и суммируем площади каждого треугольника

      double area = 0.0;

      // Используем формулу Гаусса для расчета площади треугольника
      for (size_t i = 0; i < _points.size() - 2; i++) {
         const Point &p1 = _points[0];
         const Point &p2 = _points[i + 1];
         const Point &p3 = _points[i + 2];

         double triangleArea =
             0.5 * std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) +
                             p3.x * (p1.y - p2.y)));
         area += triangleArea;
      }

      return area;
   }

   static Pentagon CreateInstance(Vector<Point> points) {
      FigureValidator::Validate(typeid(Pentagon), points);

      return Pentagon(points);
   }
};
