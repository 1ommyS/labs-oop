#include <gtest/gtest.h>
#include "Rombus.h"

// Fixture class for the tests
class RombusTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any common data or resources needed for the tests
    }

    void TearDown() override {
        // Clean up any common data or resources used by the tests
    }
};

// Parameterized test case for calculating the area of a Rombus
class RombusAreaTest : public RombusTest, public ::testing::WithParamInterface<Vector<Point>> {};

// Define the test case
TEST_P(RombusAreaTest, CalculateAreaTest) {
    // Get the input parameters for the test case
    Vector<Point> points = GetParam();

    // Create an instance of the Rombus class using the input parameters
    Rombus rombus = Rombus::CreateInstance(points);

    // Calculate the expected area of the rombus
    double expectedArea = rombus.CalculateArea();

    // Calculate the actual area using the CalculateArea() function
    double actualArea = 2.0;

    // Assert that the actual area matches the expected area
    ASSERT_DOUBLE_EQ(expectedArea, actualArea);
}

// Define the input parameters for the test case
INSTANTIATE_TEST_SUITE_P(Default, RombusAreaTest, ::testing::Values(
        // Provide different sets of input parameters for the test case
        Vector<Point>{Point(0, 0), Point(0, 4), Point(4, 0), Point(4, 4)},
        Vector<Point>{Point(0, 0), Point(0, 5), Point(5, 0), Point(5, 5)},
        // Add more sets of input parameters as needed
));

// Run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}