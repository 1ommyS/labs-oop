#pragma once

#include "vector"
#include "../GameManager.h"

using namespace Mobs;

namespace Battles {
    class BattleManager {
    private:
        std::vector<BaseObserver *> observers;
    public:
        void AddObserver(BaseObserver *observer);

        void Notify(std::string message);

        template<class AttackerType, class DefenderType>
        bool fight(AttackerType *attacker, DefenderType *defender);
        void StartBattle(std::vector<NPC*> npcs, GameManager *gameManager);
    };


}