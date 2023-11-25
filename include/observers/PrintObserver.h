#pragma once;

#include "BaseObserver.h"
#include "iostream"

namespace Observers {
class PrintObserver : public BaseObserver {
  public:
   void update(std::string message) override {
      std::cout << message << std::endl;
   }
};
}  // namespace Observers