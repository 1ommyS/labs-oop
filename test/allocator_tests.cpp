#include <gtest/gtest.h>
#include <vector>
#include "allocator.h"

TEST(MyAllocatorTest, AllocateAndDeallocate) {
   using MyIntAllocator = MyAllocator<int>;

   std::vector<int, MyIntAllocator> intVector;
   intVector.push_back(42);

   EXPECT_EQ(intVector.size(), 1);
   EXPECT_EQ(intVector[0], 42);
}

TEST(MyAllocatorTest, AllocateAndDeallocateMultiple) {
   using MyIntAllocator = MyAllocator<int>;

   std::vector<int, MyIntAllocator> intVector;
   for (int i = 0; i < 100; ++i) {
      intVector.push_back(i);
   }

   EXPECT_EQ(intVector.size(), 100);
   for (int i = 0; i < 100; ++i) {
      EXPECT_EQ(intVector[i], i);
   }
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}