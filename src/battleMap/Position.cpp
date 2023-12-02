#include "../../include/battleMap/Position.h"


Position Position::operator+(const Position& other) const {
    return Position(_x + other._x, _y + other._y);
}

Position Position::operator-(const Position& other) const {
    return Position(_x - other._x, _y - other._y);
}

bool Position::operator==(const Position& other) const {
    return _x == other._x && _y == other._y;
}

Position& Position::operator=(const Position& other) {
    _x = other._x;
    _y = other._y;
    return *this;
}

Position& Position::operator=(Position&& other) {
    _x = std::move(other._x);
    _y = std::move(other._y);
    return *this;
}