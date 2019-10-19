/*@
 *@file HumanDetector.cpp
 *@author Aruna Baijal
 *@brief This class detects humans with optimized boundaries.
 *@copyright 2019 Aruna Baijal
 */
#include <HumanDetector.hpp>

std::vector<cv::Rect> HumanDetector::detectHuman(cv::Mat image) {
  std::vector<cv::Rect> found = descriptor->detect(image);  // delegate to helper class
  std::cout << "Number of humans detected: " << found.size() << std::endl;
  return found;
}

std::vector<cv::Rect> HumanDetector::improveBoundary(
    std::vector<cv::Rect> boundary) {
  cv::Rect r(0, 0, 0, 0);
  std::vector < cv::Rect > sample;
  sample.push_back(r);
  return sample;
}
