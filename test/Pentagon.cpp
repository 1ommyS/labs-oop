#include <gtest/gtest.h>
#include "Pentagon.h"

// Fixture class for the tests
class PentagonTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(PentagonTest, CalculateAreaTest) {
    Vector<Point> points{Point(0, 0), Point(0, 4), Point(4, 0), Point(4, 4), Point(2, 6)};
    Pentagon pentagon(points);

    double expectedArea = 20.0;

    double actualArea = pentagon.CalculateArea();

    ASSERT_DOUBLE_EQ(expectedArea, actualArea);
}

TEST_F(PentagonTest, CalculateCenterTest) {
    Vector<Point> points{Point(0, 0), Point(0, 4), Point(4, 0), Point(4, 4), Point(2, 6)};
    Pentagon pentagon(points);

    Point expectedCenter(2, 2.8);

    Point actualCenter = pentagon.CalculateCenter();

    ASSERT_EQ(expectedCenter, actualCenter);
}

// Run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}