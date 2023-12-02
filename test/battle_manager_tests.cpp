#include "gtest/gtest.h"
#include "../../include/battles/BattleManager.h"
#include "../../include/mobs/Werewolf.h"
#include "../../include/mobs/Outlaw.h"
#include "../../include/mobs/Bear.h"
#include "../../include/GameManager.h"
#include "utils/DistanceCalculator.h"

using namespace Battles;
using namespace Mobs;

TEST(BattleManagerTest, Fight_WerewolfVsOutlaw) {
    // Arrange
    BattleManager battleManager;
    Werewolf werewolf;
    Outlaw outlaw;

    // Act
    bool result = battleManager.fight(&werewolf, &outlaw);

    // Assert
    EXPECT_TRUE(result);
    // Add more assertions based on the expected behavior
}

TEST(BattleManagerTest, Fight_OutlawVsBear) {
    // Arrange
    BattleManager battleManager;
    Outlaw outlaw;
    Bear bear;

    // Act
    bool result = battleManager.fight(&outlaw, &bear);

    // Assert
    EXPECT_TRUE(result);
    // Add more assertions based on the expected behavior
}

TEST(BattleManagerTest, Fight_BearVsWerewolf) {
    // Arrange
    BattleManager battleManager;
    Bear bear;
    Werewolf werewolf;

    // Act
    bool result = battleManager.fight(&bear, &werewolf);

    // Assert
    EXPECT_TRUE(result);
    // Add more assertions based on the expected behavior
}

TEST(BattleManagerTest, StartBattle) {
    // Arrange
    BattleManager battleManager;
    GameManager gameManager;
    std::vector<NPC*> npcs;
    // Add NPCs to the npcs vector

    // Act
    battleManager.StartBattle(npcs, &gameManager);

    // Assert
    // Add assertions based on the expected behavior after the battle starts
}

