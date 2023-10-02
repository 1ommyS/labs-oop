#pragma once

#include "vector.h"

class Three {
private:
    Vector<unsigned char> _digits;

public:
    Three();

    Three(const size_t &n, unsigned char t);

    Three(const std::initializer_list<unsigned char> &t);

    Three(const std::string &t);

    Three(uint64_t number);

    Three(const Three &other);

    Three(Three &&other) noexcept;

    ~Three();

    // Перегрузка операторов
    Three &operator=(const Three &other);

    Three operator+(const Three &other) const;

    Three operator-(const Three &other) const;

    Three operator++(int) const;

    Three operator--(int) const;

    bool operator==(const Three &other) const;

    bool operator!=(const Three &other) const;

    bool operator<(const Three &other) const;

    bool operator>(const Three &other) const;

    bool operator<=(const Three &other) const;

    bool operator>=(const Three &other) const;

    void print() const;

    friend std::ostream &operator<<(std::ostream &stream, const Three &three);
};
