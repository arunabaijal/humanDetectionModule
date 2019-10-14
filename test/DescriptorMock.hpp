#ifndef INCLUDE_DESCRIPTORMOCK_HPP_
#define INCLUDE_DESCRIPTORMOCK_HPP_

#include <IDescriptor.hpp>
#include <gmock/gmock.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class DescriptorMock : public virtual IDescriptor {
 public:
  MOCK_METHOD1( detect, std::vector<cv::Rect>( cv::Mat image ) );
};

#endif  // INCLUDE_DESCRIPTORMOCK_HPP_