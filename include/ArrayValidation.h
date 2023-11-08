#pragma once
#include <memory>
#include <vector>
#include "FigureList.h"
#include "Point.h"

template <typename T>
bool validate(const std::shared_ptr<Point<T>> points1,
              const std::shared_ptr<Point<T>> points2, const int size);