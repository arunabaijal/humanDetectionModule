/*@
 *@file ImageInputTest.cpp
 *@author Aruna Baijal
 *@brief Unit test cases for ImageInput
 *@copyright 2019 Aruna Baijal
 */
#include <gtest/gtest.h>
#include <exception>
#include <ImageInput.hpp>
#include <ReaderWriterMock.hpp>

TEST(imageInput, validFile) {
  ImageInput testClass;
  auto readerMock = new ReaderWriterMock();
  testClass.setReader(readerMock);
  cv::Mat sampleImage = cv::imread("../test/1_Human.jpg", 1);
  cv::Mat result = testClass.readImage("../test/1_Human.jpg");
  EXPECT_EQ(sampleImage.size(), result.size());
}

TEST(imageInput, invalidFile) {
  ImageInput testClass;
  auto readerMock = new ReaderWriterMock();
  testClass.setReader(readerMock);
  try {
    cv::Mat result = testClass.readImage("../test/23_Human.jpg");
    std::cout << result.rows << " " << result.cols << std::endl;
    FAIL();  // "Expected std::invalid file path exception
  }
  catch(std::exception& err) {
    EXPECT_EQ(err.what(), std::string("Invalid File Path"));
  }
}

