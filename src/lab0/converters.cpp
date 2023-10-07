
#include "converters.h"
#include "vector.h"

int charToNumber(char number) { return number - '0'; }

unsigned char numberToChar(unsigned int num) { return '0' + num; }

int threeToDecimal(Vector<unsigned char> digits) {
   int decimal = 0;
   int power = 1;

   for (int i = digits.size() - 1; i >= 0; i--) {
      int digit = charToNumber(digits[i]);
      decimal += digit * power;
      power *= 3;
   }

   return decimal;
}

std::string decimalToTernary(int decimal) {
   std::string ternary;

   while (decimal > 0) {
      int remainder = decimal % 3;
      char digit = '0' + remainder;
      ternary = digit + ternary;
      decimal /= 3;
   }

   return ternary;
}