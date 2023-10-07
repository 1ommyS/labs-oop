// Copyright 2023 SomeName

#include "three.h"
#include <iostream>
#include "conditionValidator.h"
#include "converters.h"
#include "vector.h"

const unsigned short ZERO_ASCII_CODE = 48;

Three::Three() = default;

Three::Three(Vector<unsigned char> _digits) { _digits = _digits; }

Three::Three(uint64_t size, char symbol) { _digits.resize(size, symbol); }

Three::Three(uint64_t n) {
   if (n == 0) {
      _digits.push_back('0');
   }

   while (n > 0) {
      unsigned char el = ZERO_ASCII_CODE + n % 10;

      if (el > ZERO_ASCII_CODE + 2 || el < ZERO_ASCII_CODE) {
         throw std::invalid_argument("Digit is over 3");
      }

      _digits.push_back(el);
      n /= 10;
   }
}

Three::Three(const std::string &str) {
   _digits.reserve(str.size());
   for (int64_t i = str.size() - 1; i >= 0; --i) {
      CheckCondition(str[i] > '2' || str[i] < '0',
                     "String contains invalid argument");
      _digits.push_back(str[i]);
   }
}

Three::Three(const Three &oth) noexcept { this->_digits = oth._digits; }

Three::Three(Three &&oth) noexcept { this->_digits = std::move(oth._digits); }

Three &Three::operator=(Three oth) noexcept {
   _digits = oth._digits;
   return *this;
}

Three &Three::operator++() noexcept {
   for (size_t i = 0; i < _digits.size(); ++i) {
      if (_digits[i] != '2') {
         ++_digits[i];
         return *this;
      }

      if (_digits[i] == '2') {
         _digits[i] = '0';
      }
   }

   _digits.push_back('1');
   return *this;
}

Three Three::operator++(int) noexcept {
   for (size_t i = 0; i < _digits.size(); ++i) {
      if (_digits[i] != '2') {
         _digits[i]++;
         return *this;
      }

      if (_digits[i] == '2') {
         _digits[i] = '0';
      }
   }

   _digits.push_back('1');
   return *this;
}

Three &Three::operator--() {
   CheckCondition(_digits.size() == 1 && _digits[0] == '0',
                  "Decrement error. Num is 0");

   for (size_t i = 0; i < _digits.size(); ++i) {
      if (_digits[i] != '0') {
         --_digits[i];

         if (&_digits[i] == &_digits[_digits.size() - 1]) {
            _digits.resize(_digits.size() - 1);
         }

         return *this;
      }

      if (_digits[i] == '0') {
         _digits[i] = '2';
      }
   }

   _digits.resize(_digits.size() - 1);
   return *this;
}

Three Three::operator--(int) {
   Three *temp = this;
   --(*temp);
   return *temp;
}

Three Three::operator+(const Three &oth) noexcept {
   int a = threeToDecimal(_digits);
   int b = threeToDecimal(oth._digits);
   int sum = a + b;
   Three resultOfSum = Three(decimalToTernary(sum));
   return resultOfSum;
}

Three Three::operator-(const Three &other) {
   CheckCondition(*this < other,
                  "The first number can't be lower than the second");

   int a = threeToDecimal(_digits);
   int b = threeToDecimal(oth._digits);
   int sum = a - b;
   Three resultOfSubstraction = Three(decimalToTernary(sum));
   return resultOfSubstraction;
}

bool Three::operator==(const Three &oth) const {
   if (_digits.size() != oth._digits.size()) {
      return false;
   }

   for (size_t i = 0; i < _digits.size(); ++i) {
      if (_digits[i] != oth._digits[i]) {
         return false;
      }
   }

   return true;
}

bool Three::operator!=(const Three &oth) const { return !(*this == oth); }

bool Three::operator>(const Three &oth) const {
   if (oth._digits.size() > _digits.size()) {
      return false;
   }

   for (int64_t i = _digits.size() - 1; i >= 0; --i) {
      if (_digits[i] > oth._digits[i]) {
         return true;

      } else if (_digits[i] < oth._digits[i]) {
         return false;
      }
   }

   return false;
}

bool Three::operator<(const Three &oth) const {
   if (oth._digits.size() > _digits.size()) {
      return true;
   }

   for (int64_t i = 0; i < _digits.size(); ++i) {
      if (_digits[i] > oth._digits[i]) {
         return false;
      }
   }
   return false;
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

std::istream &operator>>(std::istream &stream, Three &three) {
   std::string buffer;
   stream >> buffer;
   three = Three(buffer);
   return stream;
}

void Three::sumArray(Three &newObj, const Three &oth, int ost) {
   for (size_t i = 0; i < oth._digits.size(); ++i) {
      newObj._digits[i] =
          (((_digits[i] - '0') + (oth._digits[i] - '0') + ost) % 3) + '0';
      ost = ((_digits[i] - '0') + (oth._digits[i] - '0') + ost) / 3;
   }

   for (size_t i = oth._digits.size(); i < _digits.size(); ++i) {
      newObj._digits[i] = (((_digits[i] - '0') + +ost) % 3) + '0';
      ost = ((_digits[i] - '0') + ost) / 3;
      // sumArray(newObj,oth,ost);
   }
   newObj._digits[_digits.size()] = (ost + '0');
}