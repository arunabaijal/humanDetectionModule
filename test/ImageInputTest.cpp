/*@
 *@file ImageInputTest.cpp
 *@author Aruna Baijal
 *@brief Unit test cases for ImageInput
 *@copyright 2019 Aruna Baijal
 */
#include <gtest/gtest.h>
#include <ImageInput.hpp>
#include <ReaderWriterMock.hpp>

TEST(imageInput, validFile) {
  ImageInput testClass;
  auto readerMock = new ReaderWriterMock();
  testClass.setReader(readerMock);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  cv::Mat diff = sampleImage != testClass.readImage("1_Human.jpg");
  bool eq = cv::countNonZero(diff) == 0;
  EXPECT_EQ(true, eq);
}

TEST(imageInput, invalidFile) {
  ImageInput testClass;
  auto readerMock = new ReaderWriterMock();
  testClass.setReader(readerMock);
  try {
  cv::Mat result = testClass.readImage("01_Human.jpg");
    FAIL();  // "Expected std::invalid file path exception
  }
  catch(std::exception& err) {
    EXPECT_EQ(err.what(), std::string("Invalid File Path"));
  }
}
