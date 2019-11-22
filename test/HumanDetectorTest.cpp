/*@
 *@file HumanDetectorTest.cpp
 *@author Aruna Baijal
 *@brief This is the test class for HumanDetector.cpp
 *@copyright 2019 Aruna Baijal
 */
#include <gtest/gtest.h>
#include <HumanDetector.hpp>
#include <DescriptorMock.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

TEST(humanDetector, one_human_found) {
  HumanDetector detector;
  auto descriptor = new DescriptorMock();
  detector.setDescriptor(descriptor);
  cv::Rect r(446, 45, 257, 514);
  std::vector < cv::Rect > expected;
  expected.push_back(r);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  std::vector<cv::Rect> res = detector.detectHuman(sampleImage);
  std::vector<cv::Rect> result = detector.improveBoundary(res);
  EXPECT_EQ(expected, result);
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

