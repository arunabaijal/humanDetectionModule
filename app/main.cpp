/*@
 *@file main.cpp
 *@author Aruna Baijal
 *@brief This class displays a demo run of the project.
 *@copyright 2019 Aruna Baijal
 */
#include <iostream>
#include <string>
#include <HumanDetector.hpp>
#include <IDescriptor.hpp>
#include <Descriptor.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

int main(int argc, char** argv) {
  auto des = new Descriptor();
  HumanDetector detect;
  detect.setDescriptor(des);
  cv::Mat sampleImage = cv::imread("../test/1_Human.jpg", 1);
  std::vector<cv::Rect> found = detect.detectHuman(sampleImage);
  for (auto i : found) {
    std::cout << "x " << i.x << " y " << i.y << " height" << i.height
        << " width " << i.width;
  }
  return 0;
}
