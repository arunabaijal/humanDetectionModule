#include <HumanDetector.hpp>

std::vector<cv::Rect> HumanDetector::detectHuman(cv::Mat image) {
  cv::Rect r(0, 0, 0, 0);
  std::vector < cv::Rect > sample;
  sample.push_back(r);
  return sample;
}

std::vector<cv::Rect> HumanDetector::improveBoundary(
    std::vector<cv::Rect> boundary) {
  cv::Rect r(0, 0, 0, 0);
  std::vector < cv::Rect > sample;
  sample.push_back(r);
  return sample;
}
