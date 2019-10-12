/*@
 *@file IReaderWriter.hpp
 *@author Aruna Baijal
 *@brief This class controls the implementation of reader to be injected
 *@copyright 2019 Aruna Baijal
 */

#ifndef INCLUDE_IREADERWRITER_HPP_
#define INCLUDE_IREADERWRITER_HPP_

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>

class IReaderWriter {
 public:
  virtual cv::Mat read(std::String imagePath) = 0;
  virtual void drawRectangle(cv::Mat image, cv::Rect boundary) = 0;
  virtual void showImage(cv::Mat) = 0;
};

#endif  // INCLUDE_IREADERWRITER_HPP_
