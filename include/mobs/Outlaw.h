#pragma once

#include <iostream>
#include "./NPC.h"

namespace Mobs {
    class Outlaw : public NPC {
    public:
        Outlaw(int32_t x, int32_t y, std::string _name) : NPC(x, y,_name) {};

        void Die() override {
            delete this;
        }
    };
}  // namespace Mobs