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

/*TEST(humanDetector, no_human_found) {
  HumanDetector detector;
  auto detectorMock = new DescriptorMock();
  detector.setDescriptor(detectorMock);
  cv::Rect r(446, 45, 257, 514);
  std::vector < cv::Rect > expected;
  expected.push_back(r);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  EXPECT_EQ(expected, detector.detectHuman(sampleImage));
 }*/

TEST(humanDetector, one_human_found) {
  HumanDetector detector;
  auto detectorMock = new DescriptorMock();
  detector.setDescriptor(detectorMock);
  cv::Rect r(446, 45, 257, 514);
  std::vector < cv::Rect > expected;
  expected.push_back(r);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  EXPECT_EQ(expected, detector.detectHuman(sampleImage));
}

/*TEST(humanDetector, two_humans_found) {
  HumanDetector detector;
  auto detectorMock = new DescriptorMock();
  detector.setDescriptor(detectorMock);
  cv::Rect r(446, 45, 257, 514);
  std::vector < cv::Rect > expected;
  expected.push_back(r);
  cv::Mat sampleImage = cv::imread("1_Human.jpg", 1);
  EXPECT_EQ(expected, detector.detectHuman(sampleImage));
 }*/

TEST(humanDetector, should_reduce_boundary) {
  HumanDetector detector;
  cv::Rect r1(414, 0, 321, 642);
  cv::Rect r2(446, 45, 257, 514);
  EXPECT_EQ(r2, detector.improve_boundary(r1));
}

