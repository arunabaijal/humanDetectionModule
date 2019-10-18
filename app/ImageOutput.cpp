#include <ImageOutput.hpp>

void ImageOutput::showImage(cv::Mat image) {

}

cv::Mat ImageOutput::drawBoundary(cv::Mat image,
                                  std::vector<cv::Rect> boundary) {
  return getWriter()->drawRectangle(image, boundary[0]);
}
