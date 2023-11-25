#pragma once;

#include "Battle.h"
#include "Bear.h"
#include "Outlaw.h"
#include "Werewolf.h"

namespace Battles {
class WerewolfBattle : public Battle {
  public:
   void fight(Werewolf* w) override {
      // Werewolves can't fight each other
   }

   void fight(Outlaw* b) override {
      // Werewolves kill outlaws
      delete b;
   }

   void fight(Bear* b) override {
      // Werewolves can't kill Bears
   }
};
}  // namespace Battles
