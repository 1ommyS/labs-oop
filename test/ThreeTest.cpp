#include "gtest/gtest.h"
#include "three.h"


TEST(ThreeTest, IntegerConstructor) {
    Three three = Three(120);

    testing::internal::CaptureStdout();
    three.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "120\n");
}

TEST(ThreeTest, StringConstructor) {
    Three three = Three("210");

    testing::internal::CaptureStdout();
    three.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "210\n");
}

TEST(ThreeTest, CopyConstructor) {
    Three three = Three("210");
    Three copy(three);
    EXPECT_EQ(copy, three);
}

TEST(ThreeTest, PreIncrementOperator) {
    Three three = Three(210);
    ++three;

    Three resThree = (211);

    EXPECT_EQ(three, resThree);
}

TEST(ThreeTest, PostIncrementOperator) {
    Three three = Three(210);
    Three result = three++;

    Three resThree = Three(211);

    EXPECT_EQ(three, resThree);
}

TEST(ThreeTest, PreDecrementOperator) {
    Three three = Three(210);
    --three;

    Three result = Three(202);

    EXPECT_EQ(three, result);
}

TEST(ThreeTest, PostDecrementOperator) {
    Three three = Three(210);
    Three result = three--;

    Three resThree = Three(202);

    EXPECT_EQ(three, resThree);
}

TEST(ThreeTest, AdditionOperator) {
    Three three1 = Three(110);
    Three three2 = Three(102);
    Three result = three1 + three2;

    Three resThree = Three(212);
    EXPECT_EQ(result, resThree);
}

TEST(ThreeTest, SubtractionOperator) {
    Three three1 = Three(120);
    Three three2 = Three(101);
    Three result = three1 - three2;

    Three resThree = Three(12);
    EXPECT_EQ(result, resThree);
}

TEST(ThreeTest, EqualityOperator) {
    Three three1 = Three(210);
    Three three2 = Three(102);
    EXPECT_FALSE(three1 == three2);
    EXPECT_TRUE(three1 == Three(210));
}

TEST(ThreeTest, InequalityOperator) {
    Three three1 = Three(210);
    Three three2 = Three(102);
    EXPECT_TRUE(three1 != three2);
}

TEST(ThreeTest, GreaterThanOperator) {
    Three three1 = Three(210);
    Three three2 = Three(102);
    EXPECT_TRUE(three1 > three2);
}

TEST(ThreeTest, LessThanOperator) {
    Three three1 = Three(210);
    Three three2 = Three(102);
    EXPECT_FALSE(three1 < three2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}