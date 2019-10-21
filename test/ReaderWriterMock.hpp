/*@
 *@file ReaderWriteMock.hpp
 *@author Aruna Baijal
 *@brief Mock implementation for testing
 *@copyright 2019 Aruna Baijal
 */
#ifndef TEST_READERWRITERMOCK_HPP_
#define TEST_READERWRITERMOCK_HPP_

#include <string>
#include <fstream>
#include <IReaderWriter.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class ReaderWriterMock : public virtual IReaderWriter {
 public:
  cv::Mat read(std::string imagePath) {
    if (is_file_exist(imagePath)) {
      cv::Mat Z = cv::Mat::zeros(720, 1280, CV_8U);
      return Z;
    }
    cv::Mat m;
    return m;
  }
  cv::Mat drawRectangle(cv::Mat image, cv::Rect boundary) {
    cv::Mat Z = cv::Mat::zeros(720, 1280, CV_8U);
    return Z;
  }
  void showImage(cv::Mat) {
  }
  bool is_file_exist(const std::string fileName) {
    std::ifstream infile(fileName);
    return infile.good();
  }
};

#endif  // TEST_READERWRITERMOCK_HPP_
