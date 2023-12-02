#include "../include/GameManager.h"
#include "cmath"
#include "mobs/NPCFactory.h"

void GameManager::CreateBattleSettings(uint32_t radius) {
    _battleSettings = new BattleSettings(radius);
}

uint32_t GameManager::GetRadius() {
    return _battleSettings->GetRadius();
}

void GameManager::GenerateNPCs(size_t amount, NPCType type) {
    auto currentName = "";
    switch (type) {
        case NPCType::Bear:
            currentName = "Bear";
            break;
        case NPCType::Outlaw:
            currentName = "Outlaw";
            break;
        case NPCType::Werewolf:
            currentName = "Werewolf";
            break;

    }

    for (int i = 0; i < amount; i++) {
        int32_t currentRandomX = rand() % _battleSettings->MAX_X;
        int32_t currentRandomY = rand() % _battleSettings->MAX_Y;

        while (busyPositions.find({currentRandomX, currentRandomY}) != busyPositions.end()) {
            currentRandomX = rand() % _battleSettings->MAX_X;
            currentRandomY = rand() % _battleSettings->MAX_Y;
        }

        busyPositions.insert({currentRandomX, currentRandomY});

        npcs.push_back(NPCFactory::createNPC(type, currentRandomX, currentRandomY,
                                             currentName + std::to_string(currentRandomX) + " " +
                                             std::to_string(currentRandomY)));
    }
}
