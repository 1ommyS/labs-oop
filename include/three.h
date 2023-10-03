#pragma once

#include <ostream>
#include "../src/lab0/vector.cpp"
#include "vector.h"

using namespace std;

class Three {
public:
    Three();

    Three(uint64_t n);

    Three(const Three &oth) noexcept;

    Three(const std::string &str);

    Three(Three &&oth) noexcept;

    Three &operator=(Three &&oth) noexcept;

    Three &operator=(Three oth) {
        _digits = oth._digits;
        return *this;
    }

    Three &operator++() noexcept;

    Three operator++(int) noexcept;

    Three &operator--();

    Three operator--(int);

    Three operator+(const Three &oth) const noexcept;

    Three operator-(const Three &other) const;

    bool operator==(const Three &oth) const;

    bool operator!=(const Three &oth) const;

    bool operator>(const Three &oth) const;

    bool operator<(const Three &oth) const;

    void print() const;

    friend std::ostream &operator<<(std::ostream &stream, const Three &Three);

private:
    Vector<unsigned char> _digits;
};
