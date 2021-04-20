#include <benchmark/benchmark.h>
#include <opencv2/opencv.hpp>

static void BM_resize(benchmark::State& s)
{
    for(auto _ : s)
    {
        
    }
}
BENCHMARK(BM_resize);
BENCHMARK_MAIN();
