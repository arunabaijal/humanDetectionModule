/*@
 *@file HumanDetector.cpp
 *@author Aruna Baijal and Achal Vyas
 *@brief This class detects humans with optimized boundaries.
 *@copyright 2019 Aruna Baijal and Achal Vyas
 */
#include <HumanDetector.hpp>

std::vector<cv::Rect> HumanDetector::detectHuman(cv::Mat image) {
  std::vector<cv::Rect> found = descriptor->detect(image);  // delegate to helper class
  std::cout << "Number of humans detected: " << found.size() << std::endl;
  return found;
}

std::vector<cv::Rect> HumanDetector::improveBoundary(
    std::vector<cv::Rect> boundary) {
  std::vector<cv::Rect> finalBoundary;
  for (auto bound : boundary) {  // iterate over each boundary
    bound.x += cvRound(bound.width * 0.1);  // shrink boundary
    bound.width = cvRound(bound.width * 0.8);
    bound.y += cvRound(bound.height * 0.07);
    bound.height = cvRound(bound.height * 0.8);
    finalBoundary.push_back(bound);  // create new vector for optimized boundary
  }
  return finalBoundary;  // return optimized boundary
}
