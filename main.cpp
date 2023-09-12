#include <iostream>

#include "lib.h"
#include "utils.h"
#include "validation.h"
using namespace std;

int main() {
  int hours, minutes;
  string period;
  cout << "Введите через пробел часы (от 1 до 12), минуты (от 0 до 59), "
          "период (am или pm):"
       << endl;

  cin >> hours;
  cin >> minutes;
  cin >> period;

  string result = tryConvertDateTo24HrFormat(hours, minutes, period);
  cout << "Результат работы функции: " << result << endl;

  return 0;
}
