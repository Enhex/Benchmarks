#include <benchmark/benchmark.h>

#include <vector>

//int constexpr elements_count = 200; // 25 loop iterations * 8 int32 lanes = 200 elements
int constexpr elements_count = 4096; // fits L1 cache size. adding 8 more elements (1 SIMD vector) causes significant slowdown
//int constexpr elements_count = 4104;

static void bound_check(benchmark::State& state) {
  std::vector<int> v;
  for(int i=0; i < elements_count; ++i){
    v.emplace_back(i);
  }

  int sum = 0;

  for (auto _ : state) {
    for(int i = 0; i < elements_count; ++i){
      sum += v.at(i);
    }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(bound_check);

static void no_check(benchmark::State& state) {
  std::vector<int> v;
  for(int i=0; i < elements_count; ++i){
    v.emplace_back(i);
  }

  int sum = 0;

  for (auto _ : state) {
    for(int i=0; i < elements_count; ++i){
      sum += v[i];
    }
    benchmark::DoNotOptimize(sum);
  }
}
BENCHMARK(no_check);
