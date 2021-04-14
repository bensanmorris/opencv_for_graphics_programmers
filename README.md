# TLDR

A course on OpenCV for graphics programmers.

# Prerequisites

- Linux (I'm using Ubuntu 18.04)
- (On Ubuntu) gtk `sudo apt-get install libgtk2.0-dev`

# Lesson 1 - Building OpenCV

```
git clone https://github.com/bensanmorris/opencv_for_graphics_programmers.git
cd opencv_for_graphics_programmers
cmake -G "Unix Makefiles" -B build .
cd build
cmake --build . --config Release
./bin/cv_cmake
```
