#include <vector>
#include <random>
#include <cstdlib>

std::random_device rd;
std::vector<int> v;

void setup_vector()
{
	srand(rd());
	v.clear();
	for (auto i = 1000; i-- > 0;)
		v.emplace_back(rand());
}


static void NewLoop(benchmark::State& state)
{
	setup_vector();

	for (auto _ : state) {
		for (auto i = v.size(); i-- > 0;) {
			benchmark::DoNotOptimize(i);
		}
	}
}
BENCHMARK(NewLoop);


static void OldLoop(benchmark::State& state)
{
	setup_vector();

	for (auto _ : state) {
		for (size_t i = 0; i < v.size(); ++i) {
			benchmark::DoNotOptimize(i);
		}
	}
}
BENCHMARK(OldLoop);


static void OldLoopCachedSize(benchmark::State& state)
{
	setup_vector();

	for (auto _ : state) {
		const auto size = v.size();
		for (size_t i = 0; i < size; ++i) {
			benchmark::DoNotOptimize(i);
		}
	}
}
BENCHMARK(OldLoopCachedSize);


static void OldLoopCachedSize2(benchmark::State& state)
{
	setup_vector();

	for (auto _ : state) {
		for (size_t i = 0, size = v.size(); i < size; ++i) {
			benchmark::DoNotOptimize(i);
		}
	}
}
BENCHMARK(OldLoopCachedSize2);
