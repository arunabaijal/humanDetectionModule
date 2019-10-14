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
  /*
   * @brief Virtual function for interface
   * @param std::String with image path
   * @return cv::Mat image in Mat format
   */
  virtual cv::Mat read(std::String imagePath) = 0;
  /*
   * @brief Virtual function for interface
   * @param cv::Mat original image
   * @param cv::Rect boundary of detected human in image.
   * @return cv::Mat final image
   */
  virtual cv::Mat drawRectangle(cv::Mat image, cv::Rect boundary) = 0;
  /*
   * @brief Virtual function for interface
   * @param cv::Mat image to display.
   */
  virtual void showImage(cv::Mat) = 0;
};

#endif  // INCLUDE_IREADERWRITER_HPP_
