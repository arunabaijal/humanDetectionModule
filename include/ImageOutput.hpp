/*@
 *@file ImageOutput.hpp
 *@author Aruna Baijal
 *@brief This class controls the module that shows the output image with boundary
 *@copyright 2019 Aruna Baijal
 */
#ifndef INCLUDE_IMAGEOUTPUT_HPP_
#define INCLUDE_IMAGEOUTPUT_HPP_

#include <opencv2/objdetect.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <IReaderWriter.hpp>

class ImageOutput {
 private:
  cv::Mat outputImage;
  std::vector<cv::Rect> boundary;
  IReaderWriter* writer;

 public:
  /*
   * @param image Mat representation of the final image
   */
  void showImage(cv::Mat image);

  /*
   * @param image Mat representation of initial image
   * @param boundary vector representation of human boundary
   * @return Mat image of drawn image
   */
  cv::Mat drawBoundary(cv::Mat image, std::vector<cv::Rect> boundary);
};

#endif  // INCLUDE_IMAGEOUTPUT_HPP_
