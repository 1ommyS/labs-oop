#include <gtest/gtest.h>
#include "MyQueue.hpp"

TEST(MyQueueTest, Front) {
   MyQueue<int> queue;
   queue.push(1);
   queue.push(2);
   queue.push(3);

   EXPECT_EQ(queue.front(), 1);
}

TEST(MyQueueTest, PushAndPop) {
   MyQueue<int> queue;
   queue.push(1);
   queue.push(2);
   queue.push(3);

   queue.pop();
   EXPECT_EQ(queue.front(), 2);

   queue.pop();
   EXPECT_EQ(queue.front(), 3);
}

TEST(MyQueueTest, Empty) {
   MyQueue<int> queue;
   EXPECT_TRUE(queue.empty());

   queue.push(1);
   EXPECT_FALSE(queue.empty());
}

TEST(MyQueueTest, Size) {
   MyQueue<int> queue;
   EXPECT_EQ(queue.size(), 0);

   queue.push(1);
   queue.push(2);
   queue.push(3);
   EXPECT_EQ(queue.size(), 3);
}

// Add more tests as needed

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}