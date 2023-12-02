#pragma once
#include "NPC.h"
#include "Bear.h"
#include "Outlaw.h"
#include "Werewolf.h"
#include "NPCType.h"

namespace Mobs {

class NPCFactory {
  public:
   static NPC* createNPC(NPCType type, int32_t x, int32_t y, std::string name) {
      switch (type) {
         case NPCType::Outlaw:
            return reinterpret_cast<NPC*>(new Outlaw(x,y,name));
         case NPCType::Werewolf:
            return reinterpret_cast<NPC*>(new Werewolf(x,y,name));
         case NPCType::Bear:
            return reinterpret_cast<NPC*>(new Bear(x,y,name));
         default:
            return nullptr;
      }
   }
};
}  // namespace mobs
