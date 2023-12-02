#include "gtest/gtest.h"
#include "../include/GameManager.h"

TEST(GameManagerTest, CreateBattleSettings) {
  // Arrange
  GameManager gameManager;

  // Act
  gameManager.CreateBattleSettings(10);

  // Assert
  EXPECT_EQ(gameManager.GetRadius(), 10);
}

TEST(GameManagerTest, GenerateNPCs) {
  // Arrange
  GameManager gameManager;
  gameManager.CreateBattleSettings(10);

  // Act
  gameManager.GenerateNPCs(5, NPCType::Bear);

  // Assert
  EXPECT_EQ(gameManager.getNPCs().size(), 5);
  for (const auto& npc : gameManager.getNPCs()) {
    EXPECT_EQ(npc->getType(), NPCType::Bear);
  }

  // Check that all positions are unique
  auto busyPositions = gameManager.getBusyPositions();
  EXPECT_EQ(busyPositions.size(), 5);
  for (const auto& position : busyPositions) {
    EXPECT_EQ(std::count(busyPositions.begin(), busyPositions.end(), position), 1);
  }
}