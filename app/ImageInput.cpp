#include <ImageInput.hpp>

cv::Mat ImageInput::readImage(std::string imagePath) {
  return getReader()->read(imagePath);
}
