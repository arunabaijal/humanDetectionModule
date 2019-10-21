/*@
 *@file HumanDetector.hpp
 *@author Aruna Baijal and Achal Vyas
 *@brief This class controls the module that detects humans in an image vector
 *@copyright 2019 Aruna Baijal and Achal Vyas
 */
#ifndef INCLUDE_HUMANDETECTOR_HPP_
#define INCLUDE_HUMANDETECTOR_HPP_

#include <iostream>
#include <IDescriptor.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/fast_math.hpp>

class HumanDetector {
 private:
  IDescriptor* descriptor;
  std::vector<cv::Rect> boundary;
  cv::Mat imageFrame;

 public:
  /*
   * @param image Mat representation of the image
   * @return vector<Rect> value of boundaries detected
   */
  std::vector<cv::Rect> detectHuman(cv::Mat image);

  /*
   * @param boundary vector<Rect> detected boundary
   * @return vector<Rect> optimised boundary vector
   */
  std::vector<cv::Rect> improveBoundary(std::vector<cv::Rect> boundary);

  std::vector<cv::Rect> getBoundary() const {
    return boundary;
  }

  void setBoundary(std::vector<cv::Rect> boundary) {
    this->boundary = boundary;
  }

  cv::Mat getImageFrame() const {
    return imageFrame;
  }

  void setImageFrame(cv::Mat imageFrame) {
    this->imageFrame = imageFrame;
  }

  IDescriptor* getDescriptor() const {
    return descriptor;
  }

  void setDescriptor(IDescriptor* descriptor) {
    this->descriptor = descriptor;
  }
};

#endif  // INCLUDE_HUMANDETECTOR_HPP_
