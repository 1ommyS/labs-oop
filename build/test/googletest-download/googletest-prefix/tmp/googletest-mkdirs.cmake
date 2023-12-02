# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-src"
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-build"
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix"
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix/tmp"
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix/src/googletest-stamp"
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix/src"
  "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/1ommy/university/2course/labs-oop/build/test/googletest-download/googletest-prefix/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
