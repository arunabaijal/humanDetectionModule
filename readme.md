# Human Detection Module
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

Our module will be able to identify multiple humans in an image. The final deliverable of our module will be a set of 
images with location information of the detected humans. The robot's system will be able to use this location 
information. We are assuming the input and output of our module to be a set of static images.

The module is still under development. After the final stage of development, the module will be capable of detecting
multiple humans within a frame. We will add results and performance examples by the end of phase 2.


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
- Although the repository contains OpenCV library under the vendor directory, please update you system with necessary dependencies.
- Run the commands below to install OpenCV dependencies before cloning the repository:
```shell script
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```
 
## Standard install via command-line

- Switch to the directory where you want to clone this repository
- Run the following command:
```shell script
git clone --recursive https://travis-ci.org/urastogi885/humanDetectionModule
mkdir build
cd build/
cmake ..
make
```

## Accessing the UML Diagrams

- Open the directory of the project
- Access UML diagrams from the *initial* folder located within *UML* sub-directory

## Run

Within the *build* sub-directory, run:
```shell script
./app/shell-app
```
This command will show nothing after execution as implementation has not been completed yet.

## Test

Within the *build* sub-directory, run:
```shell script
./test/cpp-test
```

## Demo

## Phase-1 Issues

- TDD not completed for all classes such as ImageOutput
