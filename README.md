# TLDR

Originally this was going to introduce OpenCV to people already familiar with graphics programming but has since changed to also include those with no prior graphics programming experience (so ignore the repo's title as no prior knowledge is assumed).

# Prerequisites

(Linux - Ubuntu 18.04)

- gtk: `sudo apt-get install libgtk2.0-dev`
- CMake: `sudo apt-get install cmake`
- gcc: `sudo apt-get install build-essential`
- git: `sudo apt-get install git`

(Windows)

- [CMake](https://cmake.org/download/)
- Visual Studio 2017

# Lesson 1 - Building OpenCV
Let's build a minimal OpenCV and a small test application that will activate your laptop's camera and start grabbing video frames:

Linux:
```
git clone https://github.com/bensanmorris/opencv_for_graphics_programmers.git
cd opencv_for_graphics_programmers
cmake -G "Unix Makefiles" -B build .
cd build
cmake --build . --config Release
./bin/lesson1
```
Windows:
```
git clone https://github.com/bensanmorris/opencv_for_graphics_programmers.git
cd opencv_for_graphics_programmers
cmake -B build -G "Visual Studio 15 2017" -A x64 .
cd build
cmake --build . --config Release
./bin/Release/lesson1
```
If all goes well you should see a window displaying your webcam output:

![](lesson1.png)

The OpenCV library build is customisable. Above we built what is referred to as a "static" build of OpenCV (as opposed to dynamic). This means that the OpenCV library routines are built into our OpenCV applications for ease of portability. In future lessons (when we look at combining OpenCV and Tensorflow, we will be using a dynamic build of OpenCV which is controlled via the OpenCV build option BUILD_SHARED_LIBS and associated rpath issues - rpath being the mechanism through which an executable locates its shared libraries on linux). If you want to explore OpenCV build options and play with them then simply:
```
grep -lr OCV_OPTION *
```

And then add the option and its value to the top of this lesson's CMakeLists.txt file eg:
```
set(BUILD_SHARED_LIBS ON)
```
## Building OpenCV on Android

If you're interested in building OpenCV on Android (on a linux host) then follow the instructions below.

Android (Linux host):
```
git clone https://github.com/bensanmorris/opencv_for_graphics_programmers.git
cd opencv_for_graphics_programmers
```
Modify as appropriate (to point to your Android SDK / NDK locations specifying the desired target architecture):
```
export ANDROID_VERSION=26
export ANDROID_SDK_ROOT=/home/ben/Android/Sdk
export ANDROID_NDK_HOME=/home/ben/Android/Sdk/ndk/18.1.5063045
export arch=armeabi-v7a
```
Then build:
```
mkdir build_android
cd build_android

cmake .. -DCMAKE_BUILD_TYPE=$buildType -DCMAKE_SYSTEM_NAME=Android -DCMAKE_SYSTEM_VERSION=${ANDROID_VERSION} -DCMAKE_ANDROID_NDK=$ANDROID_NDK_HOME -DCMAKE_ANDROID_ARCH_ABI=$arch -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=clang -DCMAKE_ANDROID_STL_TYPE=c++_shared -DBUILD_JAVA=OFF -DBUILD_ANDROID_EXAMPLES=OFF
cmake --build . --config Release
```
