set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    ImageOutputTest.cpp
    ImageInputTest.cpp
    HumanDetectorTest.cpp
    ${CMAKE_SOURCE_DIR}/ImageOutput.cpp
    ${CMAKE_SOURCE_DIR}/ImageInput.cpp
    ${CMAKE_SOURCE_DIR}/HumanDetector.cpp
)
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest)
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
