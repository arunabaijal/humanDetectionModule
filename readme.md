# Human Detection Module
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![Build Status](https://travis-ci.org/urastogi885/humanDetectionModule.svg?branch=master)](https://travis-ci.org/urastogi885/humanDetectionModule)
[![Coverage Status](https://coveralls.io/repos/github/urastogi885/humanDetectionModule/badge.svg?branch=master)](https://coveralls.io/github/urastogi885/humanDetectionModule?branch=master)
---

## Overview

Human Detection module for ACME Robotics with:

- cmake
- googletest

We are designing a new human detection module by incorporating high-quality software engineering practices for Acme
Robotics to take our deliverable, finish development, and integrate it into their product.

Detection and avoidance of human obstacles play a crucial role in any self-driving system. The design and development of
real-time obstacle detection systems are currently one of the most demanding components in the autonomous industry.
To address real-life problems involved in obstacle detection, a plethora of sensors such as LIDARs, Radars, and cameras,
are being used in the industry. We are making use of the most readily available resource, images, to identify human 
obstacles.

The final deliverable of our module includes source files and license. We have included a simple demo to demonstrate the
functioning of the module. Upon running the demo, an image with a human detected pops up on your screen. After that, 
if you press any key, real world coordinates are displayed on your console. For further details on demo, refer the 
*Demo* section given below.



## Team Members

All of the team members are pursuing M.Eng. in Robotics at the University of Maryland.

- Umang Rastogi - B.Tech in Electronics & Communication Engineering
- Aruna Baijal - B.Tech in Computer Science & Engineering
- Achal Vyas - B.Tech in Mechanical Engineering

## License

- This module has been developed under the 3-Clause BSD License.
- Please go through the [*LICENSE*](https://github.com/urastogi885/humanDetectionModule/blob/phase1/LICENSE)
file before cloning the repository.

## AIP and Sprint Documents

- Click on this [*link*](https://docs.google.com/spreadsheets/d/1oHHijKNsoFVp84mNC5g5sJ4BwJQwT6XpO5uRFw9AMzE/edit?usp=sharing)
to access our AIP Google Sheet.
- Click on this [*link*](https://docs.google.com/document/d/13PsjxV7XgBc0alKm0SCArrKI3s-3ExToed2AtDfnuaQ/edit?usp=sharing)
to access our Sprint notes document.

## Install OpenCV

- The module utilizes features of OpenCV.
- Run the commands below to install OpenCV before cloning the repository:
    - Update your system:
    ```shell script
    sudo apt update
    sudo apt upgrade
    ```
  
    - Install OpenCV Dependencies:  
    ```shell script
    sudo apt install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
    sudo apt install python3.5-dev python3-numpy libtbb2 libtbb-dev
    sudo apt install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
    ```
  
    - Install OpenCV:
    ```shell script
    git clone https://github.com/opencv/opencv.git
    cd opencv 
    git checkout 3.3.0 
    cd ..
    git clone https://github.com/opencv/opencv_contrib.git
    cd opencv_contrib
    git checkout 3.3.0
    cd ..
    cd opencv
    mkdir build
    cd build
    cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D INSTALL_C_EXAMPLES=ON -D WITH_TBB=ON -D WITH_V4L=ON -D WITH_QT=ON -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules -D BUILD_EXAMPLES=ON ..
    make -j$(nproc)
    sudo make install
    sudo /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
    sudo ldconfig
    ```
    
## Standard install via command-line

- Switch to the directory where you want to clone this repository
- Run the following command:
```shell script
git clone --recursive https://github.com/urastogi885/humanDetectionModule
mkdir build
cd build/
cmake ..
make
```

## Accessing the UML Diagrams

- Open the directory of the project
- Access UML diagrams from the *initial* and *revised* folder located within *UML* sub-directory

## Run

Within the *build* sub-directory, run:
```shell script
./app/shell-app {filePath}
```

## Test

Within the *build* sub-directory, run:
```shell script
./test/cpp-test
```

## Demo

Within the *build* sub-directory, run:
```shell script
./app/shell-app ../test/1_Human.jpg
```

- Upon running the above command, image with human detected will be displayed on your screen.
- Now, press any key to display real world coordinates on your console.
