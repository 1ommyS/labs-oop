#pragma once

#include <iostream>

struct Position {
    Position() : _x(0), _y(0) {};

    Position(int32_t x, int32_t y) : _x(x), _y(y) {};

    Position(Position &&other) noexcept: _x(other._x), _y(other._y) {};

    Position operator+(const Position &other) const;

    Position operator-(const Position &other) const;

    bool operator==(const Position &other) const;

    Position &operator=(const Position &other);

    Position &operator=(Position &&other);

    int32_t GetX() {
        return _x;
    }
    int32_t GetY() {
        return _y;
    }

private:
    int32_t _x = 0;
    int32_t _y = 0;

};