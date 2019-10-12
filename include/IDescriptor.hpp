/*@
 *@file IDescriptor.hpp
 *@author Aruna Baijal
 *@brief This class controls the implementation of descriptor to be injected
 *@copyright 2019 Aruna Baijal
 */
#ifndef INCLUDE_IDESCRIPTOR_HPP_
#define INCLUDE_IDESCRIPTOR_HPP_

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class IDescriptor {
 public:
  virtual std::vector<cv::Rect> detect(cv::Mat image) = 0;
};

#endif  // INCLUDE_IDESCRIPTOR_HPP_
