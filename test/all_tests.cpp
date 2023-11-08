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

TEST(PentagonPointConstructor, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> PentPoints =
       std::shared_ptr<Point<double>>(new Point<double>[5]);
   PentPoints.get()[0] = Point<double>{0, 0};
   PentPoints.get()[1] = Point<double>{2, 0};
   PentPoints.get()[2] = Point<double>{22, 2};
   PentPoints.get()[3] = Point<double>{3, 12};
   PentPoints.get()[4] = Point<double>{5, 8};

   // act
   Pentagon<double> pentagon{PentPoints};

   // assert
   bool res = validateArray(PentPoints, pentagon.getPoints(), 5);
   EXPECT_EQ(res, true);
}

TEST(PentagonSideZeroLengthValueExeption, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> PentPoints =
       std::shared_ptr<Point<double>>(new Point<double>[5]);
   PentPoints.get()[0] = Point<double>{0, 0};
   PentPoints.get()[1] = Point<double>{22, 2};
   PentPoints.get()[2] = Point<double>{22, 2};
   PentPoints.get()[3] = Point<double>{3, 12};
   PentPoints.get()[4] = Point<double>{5, 8};

   // assert
   EXPECT_THROW(Pentagon<double> pentagon{PentPoints};, std::invalid_argument);
}

TEST(PentagonNeigboursSidesAreParelelValueExeption, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> PentPoints =
       std::shared_ptr<Point<double>>(new Point<double>[5]);
   PentPoints.get()[0] = Point<double>{1, 1};
   PentPoints.get()[1] = Point<double>{2, 2};
   PentPoints.get()[2] = Point<double>{3, 3};
   PentPoints.get()[3] = Point<double>{4, 4};
   PentPoints.get()[4] = Point<double>{5, 8};

   // assert
   EXPECT_THROW(Pentagon<double> pentagon{PentPoints};, std::invalid_argument);
}

TEST(PentagonCenter, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> PentPoints =
       std::shared_ptr<Point<double>>(new Point<double>[5]);
   PentPoints.get()[0] = Point<double>{0, 0};
   PentPoints.get()[1] = Point<double>{2, 0};
   PentPoints.get()[2] = Point<double>{22, 2};
   PentPoints.get()[3] = Point<double>{3, 12};
   PentPoints.get()[4] = Point<double>{5, 8};
   Point<double> expectedCenter = Point<double>{6.4, 4.4};
   Pentagon<double> pentagon{PentPoints};
   // act

   Point<double> center = pentagon.center();
   // assert

   EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
   EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
}

TEST(PentagonSquare, BasicAssertions) {
   // arrange
   std::shared_ptr<Point<double>> PentPoints =
       std::shared_ptr<Point<double>>(new Point<double>[5]);
   PentPoints.get()[0] = Point<double>{0, 0};
   PentPoints.get()[1] = Point<double>{2, 0};
   PentPoints.get()[2] = Point<double>{22, 2};
   PentPoints.get()[3] = Point<double>{3, 12};
   PentPoints.get()[4] = Point<double>{5, 8};
   Pentagon<double> pentagon{PentPoints};
   double expectedSquare = 113;
   // act

   double square = (double)pentagon;
   // assert

   EXPECT_DOUBLE_EQ(square, expectedSquare);
}

TEST(FigureListRemove, BasicAssertions) {
   // arrange
   Point<double>* po = new Point<double>[4];
   std::shared_ptr<Point<double>> TrapPoints =
       std::shared_ptr<Point<double>>(po);
   TrapPoints.get()[0] = Point<double>{0, 0};
   TrapPoints.get()[1] = Point<double>{7, 0};
   TrapPoints.get()[2] = Point<double>{2, 3};
   TrapPoints.get()[3] = Point<double>{6, 3};

   std::shared_ptr<Point<double>> RombPoints =
       std::shared_ptr<Point<double>>(new Point<double>[4]);
   RombPoints.get()[0] = Point<double>{0, 0};
   RombPoints.get()[1] = Point<double>{2, 0};
   RombPoints.get()[2] = Point<double>{2, 2};
   RombPoints.get()[3] = Point<double>{0, 2};

   std::shared_ptr<Point<double>> PentPoints =
       std::shared_ptr<Point<double>>(new Point<double>[5]);
   PentPoints.get()[0] = Point<double>{0, 0};
   PentPoints.get()[1] = Point<double>{2, 0};
   PentPoints.get()[2] = Point<double>{22, 2};
   PentPoints.get()[3] = Point<double>{3, 12};
   PentPoints.get()[4] = Point<double>{5, 8};

   std::vector<std::string> expectedFigures;

   expectedFigures.push_back("Pentagon");
   expectedFigures.push_back("Trap");
   expectedFigures.push_back("Romb");

   FigureList<Figure<double>*> list;

   list.push_back(dynamic_cast<Figure<double>*>(new Trap(TrapPoints)));
   list.push_back(dynamic_cast<Figure<double>*>(new Pentagon(PentPoints)));
   list.push_back(dynamic_cast<Figure<double>*>(new Romb(RombPoints)));

   // act

   list.remove(1);

   int res = list.getSize();
   // assert

   EXPECT_EQ(res, 2);
}

TEST(FigureListIndBelowZero, BasicAssertions) {
   // arrange
   FigureList<Figure<double>*> list;

   // assert
   EXPECT_THROW(list[-4];, std::invalid_argument);
}

TEST(FigureListIndBiggerThanSize, BasicAssertions) {
   // arrange
   FigureList<Figure<double>*> list;

   // assert
   EXPECT_THROW(list[2];, std::invalid_argument);
}