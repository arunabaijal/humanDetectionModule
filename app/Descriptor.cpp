/*@
 *@file Descriptor.cpp
 *@author Aruna Baijal
 *@brief This class uses HOGDescriptor to detect humans in an image.
 *@copyright 2019 Aruna Baijal
 */
#include <Descriptor.hpp>

std::vector<cv::Rect> Descriptor::detect(cv::Mat image) {
  descriptor.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());  // use trained svm from opencv
  std::vector<cv::Rect> detected;
  descriptor.detectMultiScale(image, detected, 0, cv::Size(8, 8), cv::Size(),
                              1.05, 2, false);  // using appropriate parameters
  return detected;
}
