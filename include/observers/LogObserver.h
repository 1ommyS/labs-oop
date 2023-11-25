#pragma once;

#include "BaseObserver.h"
#include "fstream"
#include "iostream"

namespace Observers {
class LogObserver : public BaseObserver {
  public:
   void update(std::string message) override {
      std::ofstream logFile("log.txt", std::ios_base::app);
      logFile << message << std::endl;
   }
};
}  // namespace Observers