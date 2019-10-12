/*@
 *@file Descriptor.hpp
 *@author Aruna Baijal
 *@brief This class controls the actual source implementation of descriptor
 *@copyright 2019 Aruna Baijal
 */
#ifndef INCLUDE_DESCRIPTOR_HPP_
#define INCLUDE_DESCRIPTOR_HPP_

#include <IDescriptor.hpp>
#include <opencv2/objdetect.hpp>

class Descriptor : public IDescriptor {
 private:
  cv::HOGDescriptor descriptor;
 public:
  /*
   * @param cv::Mat image to detect humans in.
   * @return std::vector<cv::Rect> with detected humans.
   */
  std::vector<cv::Rect> detect(cv::Mat image);
};

#endif  // INCLUDE_DESCRIPTOR_HPP_
