/*@
 *@file       ImageInput.cpp
 *@author     Umang Rastogi
 *@brief      Source file to take image as an input
 *@copyright  2019 Umang Rastogi
 */

#include <ImageInput.hpp>

cv::Mat ImageInput::readImage(std::string imagePath) {
  // get mat format of image from image reader
  return getReader()->read(imagePath);
}
