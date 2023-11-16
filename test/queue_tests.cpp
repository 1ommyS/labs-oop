#include "gtest/gtest.h"
#include "queue.h"

TEST(QueueTest, EmptyQueue) {
   MAI::Queue<int, std::allocator<int>> queue;
   EXPECT_TRUE(queue.empty());
   EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, PushAndPop) {
   MAI::Queue<int, std::allocator<int>> queue;
   queue.push(1);
   queue.push(2);
   queue.push(3);

   EXPECT_FALSE(queue.empty());
   EXPECT_EQ(queue.size(), 3);

   queue.pop();
   EXPECT_EQ(queue.front(), 2);

   queue.pop();
   EXPECT_EQ(queue.front(), 3);

   queue.pop();
   EXPECT_TRUE(queue.empty());
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}