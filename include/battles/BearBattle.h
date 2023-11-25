#pragma once;

#include "Battle.h"
#include "Bear.h"
#include "Outlaw.h"
#include "Werewolf.h"

namespace Battles {
class BearBattle : public Battle {
  public:
   void fight(Werewolf* w) override {
      // Bears kill Werewolves
      delete w;
   }

   void fight(Outlaw* b) override {
      // Bears can't kill Bandits
   }

   void fight(Bear* b) override {
      // Bears can't fight each other
   }
};
}  // namespace Battles
