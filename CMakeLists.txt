cmake_minimum_required(VERSION 3.14)
include(FetchContent)
project(cv_for_everyone)

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

# collect the opencv include dirs
macro(collect_include_dirs result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${curdir}/${child})
            list(APPEND dirlist ${curdir}/${child}/include)
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()
collect_include_dirs(OPENCV_INCLUDE_DIRS ${OpenCV_SOURCE_DIR}/modules)
list(APPEND OPENCV_INCLUDE_DIRS 
	${CMAKE_CURRENT_BINARY_DIR}
    ${OpenCV_SOURCE_DIR}/include)

# lesson 1 app
add_executable(lesson1 main.cpp)
target_link_libraries(lesson1 PRIVATE opencv_world)
target_include_directories(lesson1 PRIVATE ${OPENCV_INCLUDE_DIRS})
