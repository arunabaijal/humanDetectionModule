/*@
 *@file       ImageInput.cpp
 *@author     Umang Rastogi
 *@brief      Source file to controls the actual source implementation of reader
 *@copyright  2019 Umang Rastogi
 */

#include <ReaderWriter.hpp>

cv::Mat ReaderWriter::read(std::string imagePath) {
  // convert the image file into Mat format
  cv::Mat cvImage = cv::imread(imagePath);
  // check validity of image
  if (cvImage.empty()) {
    throw "Invalid file path";
  }
  return cv::imread(imagePath);;
}

cv::Mat ReaderWriter::drawRectangle(cv::Mat image, cv::Rect boundary) {
  // update image by drawing rectangle on it
  // refer opencv library for documentation of rectangle method
  cv::rectangle(image, boundary.tl(), boundary.br(), cv::Scalar(255, 0, 0), 1);
  return image;
}

void ReaderWriter::showImage(cv::Mat image) {
  // display image on screen
  cv::imshow("Detector", image);
}
