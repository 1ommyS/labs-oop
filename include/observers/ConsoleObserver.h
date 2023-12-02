#pragma once

#include "BaseObserver.h"
#include "iostream"

namespace Observers {
class ConsoleObserver : public BaseObserver {
  public:
   void log(std::string message) override {
      std::cout << message << std::endl;
   }
};
}  // namespace Observers