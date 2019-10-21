/*@
 *@file IDescriptor.hpp
 *@author Aruna Baijal
 *@brief This interface controls the implementation of descriptor to be injected
 *@copyright 2019 Aruna Baijal
 */
#ifndef INCLUDE_IDESCRIPTOR_HPP_
#define INCLUDE_IDESCRIPTOR_HPP_

#include <vector>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class IDescriptor {
 public:
  /*
   * @brief Virtual function for interface
   * @param cv::Mat image to detect humans in.
   * @return std::vector<cv::Rect> with detected humans.
   */
  virtual std::vector<cv::Rect> detect(cv::Mat image) = 0;
};

#endif  // INCLUDE_IDESCRIPTOR_HPP_
