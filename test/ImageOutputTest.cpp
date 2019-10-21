/*@
 *@file ImageOutputTest.cpp
 *@author Aruna Baijal
 *@brief Unit test cases for ImageOutput
 *@copyright 2019 Aruna Baijal
 */
#include <gtest/gtest.h>
#include <ImageOutput.hpp>
#include <ReaderWriterMock.hpp>

TEST(imageOutput, drawBoundary) {
  ImageOutput testClass;
  auto writerMock = new ReaderWriterMock();
  testClass.setWriter(writerMock);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  cv::Rect r1(414, 0, 321, 642);
  std::vector<cv::Rect> detectedMock;
  detectedMock.push_back(r1);
  cv::Mat diff = sampleImage
      != testClass.drawBoundary(sampleImage, detectedMock);
  bool eq = cv::countNonZero(diff) == 0;
  EXPECT_EQ(true, eq);
}

