#ifndef INCLUDE_DESCRIPTORMOCK_HPP_
#define INCLUDE_DESCRIPTORMOCK_HPP_

#include <IDescriptor.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class DescriptorMock : public virtual IDescriptor {
 public:
  std::vector<cv::Rect> detect(cv::Mat image) {
    cv::Rect r1(414, 0, 321, 642);
    std::vector<cv::Rect> detectedMock;
    detectedMock.push_back(r1);
    return detectedMock;
  }
};

#endif  // INCLUDE_DESCRIPTORMOCK_HPP_
