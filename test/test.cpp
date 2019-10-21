/*@
 *@file test.cpp
 *@author Aruna Baijal
 *@brief Running all test cases
 *@copyright 2019 Aruna Baijal
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
