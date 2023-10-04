#pragma once

#include <ostream>
#include "../src/lab0/Vector.cpp"
#include "Vector.h"

class Three {
   friend class ThreeBuilder;

  public:
   Three();

   Three(uint64_t n);

   Three(Vector<unsigned char>);

   Three(const Three &oth) noexcept;

   Three(const std::string &str);

   Three(Three &&) noexcept;

   Three &operator=(Three &&) noexcept;

   Three &operator=(Three oth) noexcept;

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

   class ThreeBuilder {
     public:
      ThreeBuilder() = default;

      ThreeBuilder &withDigits(const Vector<unsigned char> &digits) {
         _digits = digits;
         return *this;
      }

      ThreeBuilder &withDigits(uint64_t n) { return *this; }

      ThreeBuilder &withDigits(std::string str) { return *this; }

      Three build() { return Three(_digits); }

     private:
      Vector<unsigned char> _digits;
   };

   inline static ThreeBuilder builder() { return ThreeBuilder(); }

  private:
   Vector<unsigned char> _digits;
};
