#pragma once

#include <iostream>

namespace Battles {
    class BattleSettings {
    private:
        uint32_t attackRadius = 1;
    public:
        const int32_t MAX_X = 500;
        const int32_t MAX_Y = 500;

        BattleSettings(uint32_t radius) : attackRadius(radius) {};

        uint32_t GetRadius() {
            return attackRadius;
        }
    };
}
