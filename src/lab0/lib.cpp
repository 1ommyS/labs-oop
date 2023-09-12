// Copyright 2023 SomeName

#include <iomanip>
#include <iostream>
#include <sstream>

#include "lib.h"
#include "validation.h"

std::string convertDateTo24HrFormat(int hours, int minutes,
                                    const std::string& period) {
  validateInput(hours, minutes, period);

  if (hours == 12 && period == "am") {
    hours = 0;
  } else if (period == "pm" && hours < 12) {
    hours += 12;
  }
 
  std::ostringstream result;
  result << std::setfill('0') << std::setw(2) << hours << std::setw(2)
         << minutes;

  return result.str();
}
