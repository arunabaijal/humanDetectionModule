/*@
 *@file ImageOutput.cpp
 *@author Umang Rastogi
 *@brief This class displays an image with results.
 *@copyright 2019 Umang Rastogi
 */
#include <ImageOutput.hpp>

void ImageOutput::showImage(cv::Mat image) {
  // display the image on screen
  getWriter()->showImage(image);
}

cv::Mat ImageOutput::drawBoundary(cv::Mat image,
                                  std::vector<cv::Rect> boundary) {
  for (auto bound : boundary) {  // in case of multiple boundaries
    getWriter()->drawRectangle(image, bound);  // call helper class
  }
  return image;
}
