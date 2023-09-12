#include <iostream>

void validateInput(int hours, int minutes, const std::string &period) {
  if (hours < 1 || hours > 12) {
    throw std::invalid_argument("Hours must be between 1 and 12.");
  }

  if (minutes < 0 || minutes > 59) {
    throw std::invalid_argument("Minutes must be between 0 and 59.");
  }

  if (period != "am" && period != "pm") {
    throw std::invalid_argument("Period must be either 'am' or 'pm'.");
  }
}