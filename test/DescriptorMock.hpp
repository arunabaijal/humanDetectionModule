/*@
 *@file DescriptorMock.hpp
 *@author Aruna Baijal
 *@brief Mock implementation for testing
 *@copyright 2019 Aruna Baijal
 */
#ifndef TEST_DESCRIPTORMOCK_HPP_
#define TEST_DESCRIPTORMOCK_HPP_

#include <gmock/gmock.h>
#include <vector>
#include <IDescriptor.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class DescriptorMock : public IDescriptor {
 public:
  MOCK_METHOD1(detect, std::vector<cv::Rect>(cv::Mat image));
  /*std::vector<cv::Rect> detect(cv::Mat image) {
    cv::Rect r1(414, 0, 321, 642);
    std::vector<cv::Rect> detectedMock;
    detectedMock.push_back(r1);
    return detectedMock;
   }*/
};

#endif  // TEST_DESCRIPTORMOCK_HPP_
