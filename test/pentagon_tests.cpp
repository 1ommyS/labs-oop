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
