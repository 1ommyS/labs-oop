#pragma once

#include "NPC.h"

namespace Mobs {

    class Werewolf : public NPC {
    public:
        Werewolf(int32_t x, int32_t y, std::string _name) : NPC(x, y, _name) {};

        void Die() override {
            delete this;
        }

        ~Werewolf();
    };

}  // namespace Mobs