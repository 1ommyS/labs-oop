#include "conditionValidator.h"
#include <iostream>

void CheckCondition(bool condition, const std::string &message) {
   if (condition) {
      throw std::invalid_argument(message);
   }
}