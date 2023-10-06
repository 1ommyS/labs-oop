#include "gtest/gtest.h"
#include "three.h"

TEST(ThreeTest, VectorConstructor) {
   Vector<unsigned char> digits = {'1', '2', '0'};
   Three three = Three(digits);

   testing::internal::CaptureStdout();
   three.print();
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "021\n");
}

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
   Three three = Three::builder().withDigits("210").build();
   Three result = three++;

   Three resThree = Three::builder().withDigits("211").build();
   Three oldThree = Three::builder().withDigits("210").build();

   EXPECT_EQ(result, oldThree);
   EXPECT_EQ(three, resThree);
}

TEST(ThreeTest, PreDecrementOperator) {
   Three three = Three::builder().withDigits("210").build();
   --three;

   Three result = Three::builder().withDigits("202").build();

   EXPECT_EQ(three, result);
}

TEST(ThreeTest, PostDecrementOperator) {
   Three three = Three::builder().withDigits("210").build();
   Three result = three--;

   Three resThree = Three::builder().withDigits("202").build();
   Three oldThree = Three::builder().withDigits("210").build();

   EXPECT_EQ(result, oldThree);
   EXPECT_EQ(three, resThree);
}

TEST(ThreeTest, AdditionOperator) {
   Three three1 = Three::builder().withDigits("110").build();
   Three three2 = Three::builder().withDigits("102").build();
   Three result = three1 + three2;

   Three resThree = Three::builder().withDigits("212").build();
   EXPECT_EQ(result, resThree);
}

TEST(ThreeTest, SubtractionOperator) {
   Three three1 = Three::builder().withDigits("120").build();
   Three three2 = Three::builder().withDigits("101").build();
   Three result = three1 - three2;

   Three resThree = Three::builder().withDigits("12").build();
   EXPECT_EQ(result, resThree);
}

TEST(ThreeTest, EqualityOperator) {
   Three three1 = Three::builder().withDigits("210").build();
   Three three2 = Three::builder().withDigits("102").build();
   EXPECT_FALSE(three1 == three2);
   EXPECT_TRUE(three1 == Three::builder().withDigits("210").build());
}

TEST(ThreeTest, InequalityOperator) {
   Three three1 = Three::builder().withDigits("210").build();
   Three three2 = Three::builder().withDigits("102").build();
   EXPECT_TRUE(three1 != three2);
}

TEST(ThreeTest, GreaterThanOperator) {
   Three three1 = Three::builder().withDigits("210").build();
   Three three2 = Three::builder().withDigits("102").build();
   EXPECT_TRUE(three1 > three2);
}

TEST(ThreeTest, LessThanOperator) {
   Three three1 = Three::builder().withDigits("210").build();
   Three three2 = Three::builder().withDigits("102").build();
   EXPECT_FALSE(three1 < three2);
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}