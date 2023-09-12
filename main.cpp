#include <iostream>
#include "lib.h"
#include "validation.h"

using namespace std;

int main() {
   int hours, minutes;
   std::string period;
   std::cout << "Введите через пробел часы (от 1 до 12), минуты (от 0 до 59), "
                "период (am или pm):"
             << std::endl;

   std::cin >> hours;
   std::cin >> minutes;
   std::cin >> period;

   try {
      std::string result = convertDateTo24HrFormat(hours, minutes, period);
      std::cout << "Результат работы функции: " << result << std::endl;
   } catch (const std::invalid_argument& e) {
      std::cerr << e.what() << std::endl;
   }

   return 0;
}
