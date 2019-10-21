#include <ImageOutput.hpp>

void ImageOutput::showImage(cv::Mat image) {
  // display the image on screen
  getWriter()->showImage(image);
}

cv::Mat ImageOutput::drawBoundary(cv::Mat image,
                                  std::vector<cv::Rect> boundary) {
  for (auto bound : boundary) {
    getWriter()->drawRectangle(image, bound);
  }
  return image;
}
