/*@
 *@file ReaderWriteMock.hpp
 *@author Aruna Baijal
 *@brief Mock implementation for testing
 *@copyright 2019 Aruna Baijal
 */
#ifndef TEST_READERWRITERMOCK_HPP_
#define TEST_READERWRITERMOCK_HPP_

#include <string>
#include <IReaderWriter.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class ReaderWriterMock : public virtual IReaderWriter {
 public:
  cv::Mat read(std::string imagePath) {
    cv::Mat Z = cv::Mat::zeros(3, 3, CV_8UC1);
    return Z;
  }
  cv::Mat drawRectangle(cv::Mat image, cv::Rect boundary) {
    cv::Mat Z = cv::Mat::zeros(3, 3, CV_8UC1);
    return Z;
  }
  void showImage(cv::Mat) {
  }
};

#endif  // TEST_READERWRITERMOCK_HPP_
