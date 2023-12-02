#pragma once

#include <iostream>
#include "NPC.h"

namespace Mobs {

    class Bear : public NPC {
    public:

        Bear(int32_t x, int32_t y, std::string _name) : NPC(x, y, _name) {};

        void Die() override {
            delete this;
        }
    };

}  // namespace Mobs
