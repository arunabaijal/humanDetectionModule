add_executable(shell-app main.cpp ImageOutput.cpp ImageInput.cpp HumanDetector.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
