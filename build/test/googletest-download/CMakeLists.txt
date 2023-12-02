cmake_minimum_required(VERSION 3.22)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           main
  SOURCE_DIR        "/Users/1ommy/university/2course/labs-oop/build/test/googletest-src"
  BINARY_DIR        "/Users/1ommy/university/2course/labs-oop/build/test/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
