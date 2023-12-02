#include "gtest/gtest.h"
#include "DistanceCalculator.h"
#include "NPC.h"

TEST(DistanceCalculatorTest, CalculateDistance) {
  // Arrange
  NPC npc1, npc2;
  npc1.position.SetX(0);
  npc1.position.SetY(0);
  npc2.position.SetX(3);
  npc2.position.SetY(4);

  // Act
  double result = DistanceCalculator::CalculateDistance(&npc1, &npc2);

  // Assert
  EXPECT_DOUBLE_EQ(result, 5.0);
}