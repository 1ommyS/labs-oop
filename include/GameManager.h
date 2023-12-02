#pragma once

#include "./battles/BattleSettings.h"
#include "./mobs/NPC.h"
#include "battles/BattleManager.h"
#include "mobs/NPCType.h"
#include "set"

using namespace Battles;
using namespace Mobs;


class GameManager {
private:
    bool isPaused = false;
    BattleSettings *_battleSettings;
    std::set<std::pair<int32_t, int32_t>> busyPositions;
public:
    std::vector<NPC *> npcs;

    GameManager();

    void GenerateNPCs(size_t amount, NPCType type);

    void CreateBattleSettings(uint32_t radius);

    uint32_t GetRadius();

    double CalculateDistance(NPC *pNpc, NPC *pNpc1);

    void Start();

    void Pause() { isPaused = true; };

    void Continue() { isPaused = false; };
};



