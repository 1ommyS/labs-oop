#include <gtest/gtest.h>
#include "Trapezoid.h"

class TrapezoidTest : public testing::TestWithParam<Vector<Point>> {
protected:
    void SetUp() override {
        // Set up the test environment before each test
        Vector<Point> points = GetParam();
        Trapezoid trapezoid(points);
    }

    void TearDown() override {

    }
};

TEST_P(TrapezoidTest, Constructor) {
    // Test the constructor of the Trapezoid class
    Vector<Point> points = GetParam();
    Trapezoid trapezoid(points);

    // Check that the points are correctly assigned
    EXPECT_EQ(trapezoid.GetPoints(), points);
}

TEST_P(TrapezoidTest, CalculateCenter) {
    // Test the CalculateCenter() function of the Trapezoid class
    Vector<Point> points = GetParam();
    Trapezoid trapezoid(points);

    // Perform the test
    Point center = trapezoid.CalculateCenter();

    // Check the result
    EXPECT_EQ(center.x, 1.0);
    EXPECT_EQ(center.y, 0.75);
}

TEST_P(TrapezoidTest, AreaCalculation) {
    // Test the operator double() function of the Trapezoid class
    Vector<Point> points = GetParam();
    Trapezoid trapezoid(points);

    // Perform the test
    double area = static_cast<double>(trapezoid);

    // Check the result
    EXPECT_DOUBLE_EQ(area, 1.5);
}

TEST_P(TrapezoidTest, OutputOperator) {
    // Test the output operator (<<) of the Trapezoid class
    Vector<Point> points = GetParam();
    Trapezoid trapezoid(points);

    // Perform the test
    std::stringstream ss;
    ss << trapezoid;

    // Check the result
    EXPECT_EQ(ss.str(), "(0,0)(2,0)(1,1)(1,2)");
}

TEST_P(TrapezoidTest, CreateInstance) {
    // Test the CreateInstance() static function of the Trapezoid class
    Vector<Point> points = GetParam();

    // Perform the test
    Trapezoid trapezoid = Trapezoid::CreateInstance(points);

    // Check that the points are correctly assigned
    EXPECT_EQ(trapezoid.GetPoints(), points);
}

TEST_P(TrapezoidTest, Validation) {
    // Test the validation of the Trapezoid class
    Vector<Point> points = GetParam();

    EXPECT_THROW({
                     Trapezoid trapezoid(points);
                 }, std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(Default, TrapezoidTest, testing::Values(
        Vector<Point>({Point(0, 0), Point(2, 0), Point(1, 1), Point(1, 2)}),
        Vector<Point>({Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4)}),
        Vector<Point>({Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)})
));