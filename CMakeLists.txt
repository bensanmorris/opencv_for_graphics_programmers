cmake_minimum_required(VERSION 3.14)
include(FetchContent)
project(cv_cmake)

# opencv
set(BUILD_opencv_world ON)
set(BUILD_ANDROID_EXAMPLES OFF)
set(BUILD_DOCS OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_PERF_TESTS OFF)
set(BUILD_TESTS OFF)
set(BUILD_opencv_apps OFF)
set(INSTALL_PYTHON_EXAMPLES OFF)
set(BUILD_WITH_STATIC_CRT OFF)
set(BUILD_opencv_python2 OFF)
set(BUILD_opencv_python3 OFF)
set(WITH_CUDA OFF)
set(WITH_CUFFT OFF)
FetchContent_Declare(opencv
    GIT_REPOSITORY https://github.com/opencv/opencv.git
    GIT_TAG        "4.5.2"
)    
FetchContent_MakeAvailable(opencv)
set(OPENCV_INCLUDE_DIRS 
	${CMAKE_CURRENT_BINARY_DIR} 
	${OpenCV_SOURCE_DIR}/include
	${OpenCV_SOURCE_DIR}/modules/calib3d/include
	${OpenCV_SOURCE_DIR}/modules/core/include
	${OpenCV_SOURCE_DIR}/modules/dnn/include
	${OpenCV_SOURCE_DIR}/modules/features2d/include
	${OpenCV_SOURCE_DIR}/modules/flann/include
	${OpenCV_SOURCE_DIR}/modules/gapi/include
	${OpenCV_SOURCE_DIR}/modules/highgui/include
	${OpenCV_SOURCE_DIR}/modules/imgcodecs/include
	${OpenCV_SOURCE_DIR}/modules/imgproc/include
	${OpenCV_SOURCE_DIR}/modules/java/include
	${OpenCV_SOURCE_DIR}/modules/js/include
	${OpenCV_SOURCE_DIR}/modules/ml/include
	${OpenCV_SOURCE_DIR}/modules/objc/include
	${OpenCV_SOURCE_DIR}/modules/objdetect/include
	${OpenCV_SOURCE_DIR}/modules/photo/include
	${OpenCV_SOURCE_DIR}/modules/python/include
	${OpenCV_SOURCE_DIR}/modules/stitching/include
	${OpenCV_SOURCE_DIR}/modules/ts/include
	${OpenCV_SOURCE_DIR}/modules/video/include
	${OpenCV_SOURCE_DIR}/modules/videoio/include
	${OpenCV_SOURCE_DIR}/modules/world/include)

# app
add_executable(cv_cmake main.cpp)
target_link_libraries(cv_cmake PRIVATE opencv_world)
target_include_directories(cv_cmake PRIVATE ${OPENCV_INCLUDE_DIRS})
