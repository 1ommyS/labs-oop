#include <iostream>

using namespace std;

void validateTimeFormat(int hours, int minutes, const string &period) {
  if (hours < 1 || hours > 12) {
    throw invalid_argument("Hours must be between 1 and 12.");
  }

  if (minutes < 0 || minutes > 59) {
    throw invalid_argument("Minutes must be between 0 and 59.");
  }

  if (period != "am" && period != "pm") {
    throw invalid_argument("Period must be either 'am' or 'pm'.");
  }
}