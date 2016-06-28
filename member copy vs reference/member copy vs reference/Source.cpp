#include <celero/Celero.h>

#include <memory>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 10;
constexpr int g_iterations = 1000000;

constexpr int g_loops = 8;


class A
{
public:
	int m = 1;
};


BASELINE(Member, direct, g_samples, g_iterations)
{
	auto a = std::make_unique<A>();

	int result = 0;

	for (size_t i = 0; i < g_loops; ++i)
		celero::DoNotOptimizeAway(result += a->m);
}

BENCHMARK(Member, copy, g_samples, g_iterations)
{
	auto a = std::make_unique<A>();
	auto m = a->m;

	int result = 0;

	for (size_t i = 0; i < g_loops; ++i)
		celero::DoNotOptimizeAway(result += m);
}


BENCHMARK(Member, reference, g_samples, g_iterations)
{
	auto a = std::make_unique<A>();
	auto& m = a->m;

	int result = 0;

	for (size_t i = 0; i < g_loops; ++i)
		celero::DoNotOptimizeAway(result += m);
}