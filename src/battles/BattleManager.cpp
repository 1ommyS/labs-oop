#include "../../include/battles/BattleManager.h"
#include "typeinfo"
#include "../../include/mobs/Werewolf.h"
#include "../../include/mobs/Outlaw.h"
#include "../../include/mobs/Bear.h"
#include "utils/DistanceCalculator.h"


using namespace Battles;
using namespace Mobs;


void BattleManager::AddObserver(BaseObserver *observer) {
    observers.push_back(observer);
}

void BattleManager::Notify(std::string message) {
    for (auto observer : observers) {
        observer->log(message);
    }
}

template<class AttackerType, class DefenderType>
bool BattleManager::fight(AttackerType *attacker, DefenderType *defender) {

    if (typeid(AttackerType) == typeid(Werewolf) && typeid(DefenderType) == typeid(Outlaw)) {;
        defender->Die();

        Notify("Werewolf killed outlaw");

        return true;
    }

    if (typeid(AttackerType) == typeid(Outlaw) && typeid(DefenderType) == typeid(Bear)) {
        defender->Die();

        Notify("Outlaw killed Bear");

        return true;
    }

    if (typeid(AttackerType) == typeid(Bear) && typeid(DefenderType) == typeid(Werewolf)) {
        defender->Die();

        Notify("Bear killed Werewolf");

        return true;
    }

    return false;
}

void BattleManager::StartBattle(std::vector<NPC*> npcs, GameManager *gameManager) {
    for (size_t i = 0; i < npcs.size(); i++) {
        auto currentAttacker = npcs[i];

        for (size_t j = i + 1; j < npcs.size(); j++) {
            auto currentDefender = npcs[j];

            if (currentAttacker == nullptr || currentDefender == nullptr) continue;

            auto distanceBetweenFighters = DistanceCalculator::CalculateDistance(currentAttacker, currentDefender);

            if (distanceBetweenFighters <= (double) gameManager->GetRadius()) {
                bool resultOfFight = fight(currentAttacker, currentDefender);

                if (resultOfFight) npcs.erase(npcs.begin() + j);
            }
        }
    }
}