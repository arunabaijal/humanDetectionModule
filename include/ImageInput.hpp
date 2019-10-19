/*@
 *@file ImageInput.hpp
 *@author Aruna Baijal
 *@brief This class controls the module that takes image as in input
 *@copyright 2019 Aruna Baijal
 */
#ifndef INCLUDE_IMAGEINPUT_HPP_
#define INCLUDE_IMAGEINPUT_HPP_

#include <opencv2/objdetect.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <IReaderWriter.hpp>
#include <iostream>
#include <string>

class ImageInput {
 private:
  cv::Mat imageFrame;
  IReaderWriter* reader;

 public:
  /*
   * @param image Mat representation of the image
   * @return vector<Rect> value of boundaries detected
   */
  cv::Mat readImage(std::string imagePath);

  cv::Mat getImageFrame() const {
    return imageFrame;
  }

  void setImageFrame(cv::Mat imageFrame) {
    this->imageFrame = imageFrame;
  }

  IReaderWriter* getReader() const {
    return reader;
  }

  void setReader(IReaderWriter* reader) {
    this->reader = reader;
  }
};

#endif  // INCLUDE_IMAGEINPUT_HPP_
