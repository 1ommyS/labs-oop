#pragma once
#include "iostream"

namespace Observers {
class BaseObserver {
  public:
   virtual void log(std::string message) = 0;
};

}  // namespace Observers
