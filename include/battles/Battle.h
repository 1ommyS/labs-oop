#pragma once;
#include "Bear.h"
#include "Outlaw.h"
#include "Werewolf.h"

using namespace mobs;
namespace Battles {
class Battle {
  public:
   virtual void fight(Bear* e) = 0;
   virtual void fight(Outlaw* o) = 0;
   virtual void fight(Werewolf* w) = 0;
};
}