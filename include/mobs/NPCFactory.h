#pragma once;
#include "NPC.h"
#include "NPCType.h"

namespace mobs {

class NPCFactory {
  public:
   NPC* createNPC(NPCType type) {
      switch (type) {
         case NPCType::Outlaw:
            return new Outlaw();
         case NPCType::Werewolf:
            return new Werewolf();
         case NPCType::Bear:
            return new Bear();
         default:
            return nullptr;
      }
   }
};
}  // namespace mobs
