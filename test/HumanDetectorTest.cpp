/*@
 *@file HumanDetectorTest.cpp
 *@author Aruna Baijal
 *@brief This is the test class for HumanDetector.cpp
 *@copyright 2019 Aruna Baijal
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HumanDetector.hpp>
#include <DescriptorMock.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

using ::testing::Return;
using ::testing::_;

TEST(humanDetector, one_human_found) {
  HumanDetector detector;
  DescriptorMock* descriptor = new DescriptorMock();  // mock class
  detector.setDescriptor(descriptor);
  cv::Rect r(446, 45, 257, 514);
  std::vector < cv::Rect > expected;
  expected.push_back(r);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  cv::Rect r1(414, 0, 321, 642);
  std::vector<cv::Rect> detectedMock;
  detectedMock.push_back(r1);
  EXPECT_CALL(*descriptor, detect(_)).WillRepeatedly(  // any argument
      Return(detectedMock));  // mock implementation
  std::vector<cv::Rect> res = detector.detectHuman(sampleImage);
  std::vector<cv::Rect> result = detector.improveBoundary(res);
  EXPECT_EQ(expected, result);
  delete descriptor;
}

TEST(humanDetector, should_reduce_boundary) {
  HumanDetector detector;
  cv::Rect r1(414, 0, 321, 642);
  cv::Rect r2(446, 45, 257, 514);
  std::vector < cv::Rect > expected;
  std::vector < cv::Rect > input;
  expected.push_back(r2);
  input.push_back(r1);
  EXPECT_EQ(expected, detector.improveBoundary(input));
}
