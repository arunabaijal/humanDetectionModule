/*@
 *@file       ImageInput.cpp
 *@author     Umang Rastogi
 *@brief      Source file to take image as an input
 *@copyright  2019 Umang Rastogi
 */

#include <ImageInput.hpp>

cv::Mat ImageInput::readImage(std::string imagePath) {
  // get mat format of image from image reader
  cv::Mat cvImage = getReader()->read(imagePath);
  // check validity of image
  if (cvImage.empty()) {
    throw std::runtime_error("Invalid File Path");
  }
  return cvImage;
}
