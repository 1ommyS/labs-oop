// Copyright 2023 SomeName

#include "Three.h"
#include <iostream>
#include "ConditionValidator.h"
#include "Vector.h"

const unsigned short ZERO_ASCII_CODE = 48;

Three::Three() { _digits.push_back('0'); };

Three::Three(Vector<unsigned char> digits) { _digits = digits; }

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

Three &Three::operator=(Three &&oth) noexcept {
   this->_digits = oth._digits;
   return *this;
}

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
   (*this)++;
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

Three Three::operator+(const Three &oth) const noexcept {
   size_t min_size = std::min(_digits.size(), oth._digits.size());
   size_t max_size = std::max(_digits.size(), oth._digits.size());

   Three new_obj{static_cast<uint64_t>(std::pow(10, max_size - 1))};
   new_obj._digits[new_obj._digits.size() - 1] = '0';

   for (size_t i = 0; i < min_size; ++i) {
      new_obj._digits[i] +=
          (_digits[i] + oth._digits[i] - 2 * ZERO_ASCII_CODE) % 3;
      new_obj._digits[i + 1] +=
          (_digits[i] + oth._digits[i] - 2 * ZERO_ASCII_CODE + 1) / 3;

      if (oth._digits.size() - max_size == 0 &&
          _digits[_digits.size() - 1] + oth._digits[oth._digits.size() - 1] -
                  2 * ZERO_ASCII_CODE >
              2) {

         new_obj._digits.resize(new_obj._digits.size() + 1);
      }
   }

   return new_obj;
}

Three Three::operator-(const Three &other) const {
   CheckCondition(*this < other,
                  "The first number can't be lower than the second");

   std::string result = "";
   int carry = 0;

   size_t i = 0;
   result.reserve(_digits.size());
   while (i < _digits.size()) {
      int bit1 = (i < _digits.size()) ? _digits[i] - ZERO_ASCII_CODE : 0;
      int bit2 =
          (i < other._digits.size()) ? other._digits[i] - ZERO_ASCII_CODE : 0;

      int diff = bit1 - bit2 - carry;

      if (diff < 0) {
         diff += 3;
         carry = 1;
      } else {
         carry = 0;
      }

      result.push_back(diff + ZERO_ASCII_CODE);
      i++;
   }

   auto last_it = --result.rend();
   int64_t count_zeroes = 0;
   for (auto it = result.rbegin(); it != last_it; ++it) {
      if (*it == '0') {
         ++count_zeroes;
      } else {
         break;
      }
   }

   result.resize(result.size() - count_zeroes);
   std::reverse(result.begin(), result.end());
   return Three{result};
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

bool Three::operator!=(const Three &oth) const {
   return *this == oth ? false : true;
}

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