#include <gtest/gtest.h>

#include "lib.h"

using namespace std;

TEST(ConvertDateTo24HrFormatTest, ValidInputTest) {
  // Arrange
  int hours = 11;
  int minutes = 30;
  string period = "pm";

  // Act
  string result = convertDateTo24HrFormat(hours, minutes, period);

  // Assert
  ASSERT_EQ(result, "2330");  // 24 hour format
}

TEST(ConvertDateTo24HrFormatTest, InvalidHoursTest) {
  // Arrange
  int hours = 13;
  int minutes = 30;
  string period = "pm";

  // Act and Assert
  ASSERT_THROW(convertDateTo24HrFormat(hours, minutes, period),
               invalid_argument);
}

TEST(ConvertDateTo24HrFormatTest, InvalidMinutesTest) {
  // Arrange
  int hours = 11;
  int minutes = 60;
  string period = "pm";

  // Act and Assert
  ASSERT_THROW(convertDateTo24HrFormat(hours, minutes, period),
               invalid_argument);
}

TEST(ConvertDateTo24HrFormatTest, InvalidPeriodTest) {
  // Arrange
  int hours = 11;
  int minutes = 30;
  string period = "xx";

  // Act and Assert
  ASSERT_THROW(convertDateTo24HrFormat(hours, minutes, period),
               invalid_argument);
}

TEST(ConvertDateTo24HrFormatTest, EdgeCaseAM12ToZeroTest) {
  // Arrange
  int hours = 12;
  int minutes = 0;
  string period = "am";

  // Act
  string result = convertDateTo24HrFormat(hours, minutes, period);

  // Assert
  ASSERT_EQ(result, "0000");
}

TEST(ConvertDateTo24HrFormatTest, EdgeCasePM12NoChangeTest) {
  // Arrange
  int hours = 12;
  int minutes = 0;
  string period = "pm";

  // Act
  string result = convertDateTo24HrFormat(hours, minutes, period);

  // Assert
  ASSERT_EQ(result, "1200");
}
