#pragma once;

#include "Battle.h"
#include "Bear.h"
#include "Werewolf.h"

namespace Battles {
class OutlawBattle : public Battle {
  public:
   void fight(Werewolf* w) override {
      // Bandits can't kill Werewolves
   }

   void fight(Outlaw* b) override {
      // Bandits can't fight each other
   }

   void fight(Bear* b) override {
      // Bandits kill Bears
      delete b;
   }
};
}  // namespace Battles