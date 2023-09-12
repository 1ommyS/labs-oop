#include <iomanip>
#include <iostream>
#include <sstream>

#include "lib.h"

using namespace std;

string formatTime(int hours, int minutes) {
  ostringstream result;
  result << setfill('0') << setw(2) << hours << setw(2) << minutes;
  return result.str();
}

string tryConvertDateTo24HrFormat(int hours, int minutes,
                                  const string& period) {
  try {
    return convertDateTo24HrFormat(hours, minutes, period);
  } catch (const invalid_argument& e) {
    return e.what();
  }
}
