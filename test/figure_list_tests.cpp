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