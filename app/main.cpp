/*@
 *@file main.cpp
 *@author Achal Vyas
 *@brief This class displays a demo run of the project.
 *@copyright 2019 Achal Vyas
 */
#include <iostream>
#include <string>
#include <HumanDetector.hpp>
#include <IDescriptor.hpp>
#include <Descriptor.hpp>
#include <ImageInput.hpp>
#include <ImageOutput.hpp>
#include <ReaderWriter.hpp>
#include <IReaderWriter.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char** argv) {
  std::cout << "Running demo for human detection" << std::endl;
  auto readerWriter = new ReaderWriter();
  auto des = new Descriptor();
  HumanDetector detect;
  detect.setDescriptor(des);  // set actual implementation
  ImageInput input;
  input.setReader(readerWriter);  // set actual implementation
  cv::Mat sampleImage = input.readImage(argv[1]);  // take file name from user
  std::vector<cv::Rect> found = detect.detectHuman(sampleImage);
  std::vector<cv::Rect> optimized = detect.improveBoundary(found);
  ImageOutput output;
  output.setWriter(readerWriter);  // set actual implementation
  output.drawBoundary(sampleImage, optimized);
  std::cout << "Press any key to exit view" << std::endl;
  output.showImage(sampleImage);
  cv::waitKey();  // press any key to exit view
  std::cout << "Real world coordinates of human are:" << std::endl;
  for (auto i : optimized) {
    std::cout << "(x, y) = (" << i.x << ", " << i.y << ")" << "of height"
        << i.height << "and width " << i.width << std::endl;
  }
  return 0;
}
