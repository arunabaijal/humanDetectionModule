/*@
 *@file main.cpp
 *@author Achal Vyas
 *@brief This class displays a demo run of the project.
 *@copyright 2019 Achal Vyas
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
