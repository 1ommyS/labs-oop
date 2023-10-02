// Copyright 2023 SomeName

#include "three.h"
#include "vector.h"

Three::Three() {

}

Three::Three(const size_t &n, unsigned char t) { _digits.resize(n, t); }

Three::Three(const std::initializer_list<unsigned char> &t) {
    _digits.reserve(t.size());
    for (const auto &value: t) {
        if (value - '0' > 2)
            throw std::invalid_argument("Некорректный формат ввода");

        _digits.push_back(value);
    }
}

Three::Three(const std::string &t) : Three::Three(std::stoull(t)) {
    // Проверка на корректность ввода
    for (const char &c: t) {
        if (c < '0' || c > '2')
            throw std::invalid_argument("Некорректный формат ввода");
    }
}

Three::Three(uint64_t number) {
    uint64_t numberCopy = number;
    do {
        if (numberCopy % 10 > 2)
            throw std::invalid_argument("Некорректный формат ввода");

        char remainder = (numberCopy % 3) + '0';
        _digits.push_back(remainder);
        numberCopy /= 3;
    } while (numberCopy > 0);
}

Three::Three(const Three &other) { _digits = other._digits; }

Three::Three(Three &&other) noexcept {
    _digits = std::move(other._digits);

    other._digits.~Vector();
}

Three::~Three() { _digits.~Vector(); }

Three &Three::operator=(const Three &other) {
    this->_digits = other._digits;
    return *this;
}

bool Three::operator==(const Three &other) const {
    return this->_digits == other._digits;
}

Three Three::operator+(const Three &other) const {
    Three result;

    size_t max_size = std::max(_digits.size(), other._digits.size());

    unsigned char carry = 0;

    for (size_t i = 0; i < max_size; ++i) {
        unsigned char digit1 = i < _digits.size() ? _digits[i] : 0;
        unsigned char digit2 = i < other._digits.size() ? other._digits[i] : 0;

        unsigned char sum = digit1 + digit2 + carry;
        carry =
                sum / 3;
        sum %= 3;

        result._digits.push_back(sum);
    }

    if (carry > 0) {
        result._digits.push_back(carry);
    }

    return result;
}

Three Three::operator-(const Three &other) const {
    // Создайте новый экземпляр класса Three, чтобы хранить результат вычитания
    Three result;

    // Определите максимальный размер между _digits текущего экземпляра и _digits экземпляра other
    size_t max_size = std::max(_digits.size(), other._digits.size());

    // Переменная, чтобы хранить заем разряда
    unsigned char borrow = 0;

    for (size_t i = 0; i < max_size; ++i) {
        unsigned char digit1 = i < _digits.size() ? _digits[i] : 0;
        unsigned char digit2 = i < other._digits.size() ? other._digits[i] : 0;

        int difference = digit1 - digit2 - borrow;

        if (difference < 0) {
            difference += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result._digits.push_back(difference);
    }

    while (result._digits.size() > 1 && result._digits.back() == 0) {
        result._digits.pop_back();
    }

    return result;
}

bool Three::operator!=(const Three &other) const {
    return !(*this == other);
}

bool Three::operator<(const Three &other) const {
    if (_digits.size() < other._digits.size()) {
        return true;
    } else if (_digits.size() > other._digits.size()) {
        return false;
    }

    for (int i = _digits.size() - 1; i >= 0; --i) {
        if (_digits[i] < other._digits[i]) {
            return true;
        } else if (_digits[i] > other._digits[i]) {
            return false;
        }
    }

    return false;
}

bool Three::operator>(const Three &other) const {
    return !(*this < other) && *this != other;
}

bool Three::operator<=(const Three &other) const {
    return *this < other || *this == other;
}

bool Three::operator>=(const Three &other) const {
    return *this > other || *this == other;
}

void Three::print() const {
    for (int64_t i = _digits.size() - 1; i >= 0; --i) {
        std::cout << _digits[i];
    }

    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Three &three) {
    for (int64_t i = three._digits.size() - 1; i >= 0; --i) {
        stream << three._digits[i];
    }

    return stream;
}

