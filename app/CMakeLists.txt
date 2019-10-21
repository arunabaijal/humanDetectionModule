add_executable(shell-app main.cpp ImageOutput.cpp ImageInput.cpp HumanDetector.cpp Descriptor.cpp ReaderWriter.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(OpenCV_DIR ../vendor/opencv/build)
find_package( OpenCV REQUIRED PATHS ../vendor/opencv/build)
target_link_libraries( shell-app ${OpenCV_LIBS} )
