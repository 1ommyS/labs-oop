#pragma once;
#include "Battle.h"

class NPC {
  public:
   virtual void sayHello() = 0;
   virtual void accept(Battle* battle) = 0;
};
