set(GTEST_SHUFFLE 1)
cmake_minimum_required(VERSION 2.8)
add_executable(
    cpp-test
    test.cpp
    HumanDetectorTest.cpp
    DescriptorMock.hpp
    ../app/Descriptor.cpp
    ../app/HumanDetector.cpp
    ImageInputTest.cpp
    ReaderWriterMock.hpp
    ../app/ReaderWriter.cpp
    ../app/ImageInput.cpp
    ImageOutputTest.cpp
    ../app/ImageOutput.cpp
)
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${OpenCV_INCLUDE_DIRS}
                                           ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cpp-test PUBLIC gtest)
find_package( OpenCV REQUIRED PATHS ../vendor/opencv/build)
target_link_libraries(cpp-test PUBLIC ${OpenCV_LIBS})