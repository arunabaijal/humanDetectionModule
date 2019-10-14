set(GTEST_SHUFFLE 1)
cmake_minimum_required(VERSION 2.8)
add_executable(
    cpp-test
    test.cpp
    HumanDetectorTest.cpp
    DescriptorMock.hpp
    ${CMAKE_SOURCE_DIR}/app/Descriptor.cpp
)
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${OpenCV_INCLUDE_DIRS}
                                           ${CMAKE_CURRENT_SOURCE_DIR}
                                           ../vendor/googletest/googlemock/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS} gmock)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
find_package( OpenCV REQUIRED)
