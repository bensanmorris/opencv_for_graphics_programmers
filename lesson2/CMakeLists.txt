set(BENCHMARK_ENABLE_TESTING FALSE)
include(FetchContent)
FetchContent_Declare(googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark
)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(lesson2 main.cpp)
target_link_libraries(lesson2 PRIVATE benchmark::benchmark opencv_world)
target_include_directories(lesson2 PRIVATE ${OPENCV_INCLUDE_DIRS})

