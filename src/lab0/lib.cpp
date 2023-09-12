// Copyright 2023 SomeName

#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;


#include "lib.h"
#include "validation.h"
#include "utils.h"

string convertDateTo24HrFormat(int hours, int minutes,  const string& period) {
  validateTimeFormat(hours, minutes, period);

  if (hours == 12 && period == "am") {
    hours = 0;
  } else if (period == "pm" && hours < 12) {
    hours += 12;
  }
 
  return formatTime(hours, minutes);
}
