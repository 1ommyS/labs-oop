#include <gtest/gtest.h>

#include "three.h"

TEST(ThreeTest, DefaultConstructor) {
   Three three;
   EXPECT_EQ(three, "0");
}

TEST(ThreeTest, SizeValueConstructor) {
   Three three(5, 1);
   EXPECT_EQ(three, "11111");
}

TEST(ThreeTest, InitializerListConstructor) {
   Three three = {1, 2, 0};
   EXPECT_EQ(three, "120");
}

TEST(ThreeTest, StringConstructor) {
   Three three("10");
   EXPECT_EQ(three, "101");
}

TEST(ThreeTest, NumberConstructor) {
   Three three(7);
   EXPECT_EQ(three, "21");
}

TEST(ThreeTest, CopyConstructor) {
   Three original(3, 2);
   Three copy(original);
   EXPECT_EQ(copy, "222");
}

TEST(ThreeTest, AssignmentOperator) {
   Three original(4, 1);
   Three copy;
   copy = original;
   EXPECT_EQ(copy, "1111");
}

TEST(ThreeTest, AdditionOperator) {
   Three three1(2, 1);
   Three three2(3, 2);
   Three sum = three1 + three2;
   EXPECT_EQ(sum, "22211");
}

TEST(ThreeTest, SubtractionOperator) {
   Three three1(3, 2);
   Three three2(2, 1);
   Three difference = three1 - three2;
   EXPECT_EQ(difference, "21");
}

TEST(ThreeTest, EqualityOperator) {
   Three three1(3, 1);
   Three three2(3, 1);
   EXPECT_TRUE(three1 == three2);
}

TEST(ThreeTest, InequalityOperator) {
   Three three1(3, 1);
   Three three2(2, 1);
   EXPECT_TRUE(three1 != three2);
}

TEST(ThreeTest, LessThanOperator) {
   Three three1("21");
   Three three2("22");
   EXPECT_TRUE(three1 < three2);
}

TEST(ThreeTest, GreaterThanOperator) {
   Three three1("22");
   Three three2("21");
   EXPECT_TRUE(three1 > three2);
}

TEST(ThreeTest, LessThanOrEqualOperator) {
   Three three1("21");
   Three three2("22");
   EXPECT_TRUE(three1 <= three2);
   EXPECT_TRUE(three1 <= three1);
}

TEST(ThreeTest, GreaterThanOrEqualOperator) {
   Three three1("22");
   Three three2("21");
   EXPECT_TRUE(three1 >= three2);
   EXPECT_TRUE(three1 >= three1);
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}