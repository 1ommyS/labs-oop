#include <gtest/gtest.h>
#include "./../src/lab0/ArrayValidation.cpp"
#include "./../src/lab0/Figure.cpp"
#include "./../src/lab0/FigureList.cpp"
#include "./../src/lab0/Pentagon.cpp"
#include "./../src/lab0/Point.cpp"
#include "./../src/lab0/Romb.cpp"
#include "./../src/lab0/Trap.cpp"
#include "ArrayValidation.h"
#include "FigureList.h"
#include "Pentagon.h"
#include "Point.h"
#include "Romb.h"
#include "Trap.h"

TEST(RombPointConstructor, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{0, 0};
   RombPoints.get()[1] = Point<double>{2, 0};
   RombPoints.get()[2] = Point<double>{2, 2};
   RombPoints.get()[3] = Point<double>{0, 2};

   // act
   Romb<double> romb{RombPoints};
   bool res = validateArray(RombPoints, romb.getPoints(), 4);
   // assert

   EXPECT_EQ(res, true);
}

TEST(RombNeighboursSidesAreParralelValueExeption, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{2, 4};
   RombPoints.get()[1] = Point<double>{4, 8};
   RombPoints.get()[2] = Point<double>{2, 3};
   RombPoints.get()[3] = Point<double>{6, 3};

   // assert
   EXPECT_THROW(Romb<double> romb{RombPoints};, std::invalid_argument);
}

TEST(RombSideZeroLengthValueExeption, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{0, 0};
   RombPoints.get()[1] = Point<double>{2, 2};
   RombPoints.get()[2] = Point<double>{2, 2};
   RombPoints.get()[3] = Point<double>{0, 2};

   // assert
   EXPECT_THROW(Romb<double> romb{RombPoints};, std::invalid_argument);
}

TEST(RombOppositeSidesArentParalelValueExeption, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{2, 6};
   RombPoints.get()[1] = Point<double>{13, 4};
   RombPoints.get()[2] = Point<double>{9, 11};
   RombPoints.get()[3] = Point<double>{37, 2};

   // assert
   EXPECT_THROW(Romb<double> romb{RombPoints};, std::invalid_argument);
}

TEST(RombCenter, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{0, 0};
   RombPoints.get()[1] = Point<double>{2, 0};
   RombPoints.get()[2] = Point<double>{2, 2};
   RombPoints.get()[3] = Point<double>{0, 2};
   Romb<double> romb{RombPoints};
   Point<double> expectedCenter = Point<double>{1, 1};
   // act

   Point<double> center = romb.center();
   // assert

   EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
   EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
}

TEST(RombSquare, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{0, 0};
   RombPoints.get()[1] = Point<double>{2, 0};
   RombPoints.get()[2] = Point<double>{2, 2};
   RombPoints.get()[3] = Point<double>{0, 2};
   double expectedSquare = 4;
   // act
   Romb<double> romb{RombPoints};
   double square = (double)romb;
   // assert

   EXPECT_DOUBLE_EQ(square, expectedSquare);
}
