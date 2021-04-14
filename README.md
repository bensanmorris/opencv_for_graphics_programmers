# TLDR

A course on OpenCV for graphics programmers.

# Prerequisites

- Linux (I'm using Ubuntu 18.04)
- gtk: `sudo apt-get install libgtk2.0-dev`
- CMake: `sudo apt-get install cmake`
- gcc: `sudo apt-get install build-essential`

# Lesson 1 - Building OpenCV
Let's build a minimal OpenCV and a small test application that will activate your laptop's camera and start grabbing video frames:
```
git clone https://github.com/bensanmorris/opencv_for_graphics_programmers.git
cd opencv_for_graphics_programmers
cmake -G "Unix Makefiles" -B build .
cd build
cmake --build . --config Release
./bin/lesson1
```
