#include <ImageOutput.hpp>

void ImageOutput::showImage(cv::Mat image) {
  // display the image on screen
  cv::imshow(getOutputImage());
}

cv::Mat ImageOutput::drawBoundary(cv::Mat image,
                                  std::vector<cv::Rect> boundary) {
  setOutputImage(getWriter()->drawRectangle(image, boundary));
  return getOutputImage();
}
