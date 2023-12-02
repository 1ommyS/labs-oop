#include "GameManager.h"
#include <vector>
#include "include/mobs/NPCFactory.h"
#include "battles/BattleManager.h"


using namespace Battles;
using namespace Mobs;


int main() {

    auto gameManager = new GameManager();
    auto battleManager = new BattleManager();

    battleManager->AddObserver(new LogObserver);
    battleManager->AddObserver(new ConsoleObserver);

    gameManager->CreateBattleSettings(50);
    //gm->CreateGrid();

    gameManager->GenerateNPCs(10, NPCType::Outlaw);
    gameManager->GenerateNPCs(10, NPCType::Werewolf);
    gameManager->GenerateNPCs(10, NPCType::Bear);

    battleManager->StartBattle(gameManager->npcs, gameManager);

    return 0;
}

