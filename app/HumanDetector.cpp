/*@
 *@file HumanDetector.cpp
 *@author Aruna Baijal and Achal Vyas
 *@brief This class detects humans with optimized boundaries.
 *@copyright 2019 Aruna Baijal and Achal Vyas
 */
/*M///////////////////////////////////////////////////////////////////////////////////////
 //By downloading, copying, installing or using the software you agree to this license.
 //If you do not agree to this license, do not download, install,
 //copy or use the software.
 //
 //
 //                          License Agreement
 //               For Open Source Computer Vision Library
 //                       (3-clause BSD License)
 //
 //Copyright (c) 2019-2020, Umang Rastogi, all rights reserved.
 //Copyright (c) 2019-2020, Aruna Baijal, all rights reserved.
 //Copyright (c) 2019-2020, Achal Vyas, all rights reserved.
 //Copyright (C) 2000-2019, Intel Corporation, all rights reserved.
 //Copyright (C) 2009-2011, Willow Garage Inc., all rights reserved.
 //Copyright (C) 2009-2016, NVIDIA Corporation, all rights reserved.
 //Copyright (C) 2010-2013, Advanced Micro Devices, Inc., all rights reserved.
 //Copyright (C) 2015-2016, OpenCV Foundation, all rights reserved.
 //Copyright (C) 2015-2016, Itseez Inc., all rights reserved.
 //Third party copyrights are property of their respective owners.
 //
 //Redistribution and use in source and binary forms, with or without modification,
 //are permitted provided that the following conditions are met:
 //
 //  * Redistributions of source code must retain the above copyright notice,
 //    this list of conditions and the following disclaimer.
 //
 //  * Redistributions in binary form must reproduce the above copyright notice,
 //    this list of conditions and the following disclaimer in the documentation
 //    and/or other materials provided with the distribution.
 //
 //  * Neither the names of the copyright holders nor the names of the contributors
 //    may be used to endorse or promote products derived from this software
 //    without specific prior written permission.
 //
 //This software is provided by the copyright holders and contributors "as is" and
 //any express or implied warranties, including, but not limited to, the implied
 //warranties of merchantability and fitness for a particular purpose are disclaimed.
 //In no event shall copyright holders or contributors be liable for any direct,
 //indirect, incidental, special, exemplary, or consequential damages
 //(including, but not limited to, procurement of substitute goods or services;
 //loss of use, data, or profits; or business interruption) however caused
 //and on any theory of liability, whether in contract, strict liability,
 //or tort (including negligence or otherwise) arising in any way out of
 //the use of this software, even if advised of the possibility of such damage.
 //M*/

#include <HumanDetector.hpp>

std::vector<cv::Rect> HumanDetector::detectHuman(cv::Mat image) {
  std::vector<cv::Rect> found = descriptor->detect(image);  // delegate to helper class
  std::cout << "Number of humans detected: " << found.size() << std::endl;
  return found;
}

std::vector<cv::Rect> HumanDetector::improveBoundary(
    std::vector<cv::Rect> boundary) {
  std::vector<cv::Rect> finalBoundary;
  for (auto bound : boundary) {  // iterate over each boundary
    bound.x += cvRound(bound.width * 0.1);  // shrink boundary
    bound.width = cvRound(bound.width * 0.8);
    bound.y += cvRound(bound.height * 0.07);
    bound.height = cvRound(bound.height * 0.8);
    finalBoundary.push_back(bound);  // create new vector for optimized boundary
  }
  return finalBoundary;  // return optimized boundary
}
