#include <celero/Celero.h>

#include <map>
#include <unordered_map>

#include <random>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 75000;

constexpr int num_elements = 100;

std::mt19937 rng;
auto rand_int = std::bind(std::uniform_int_distribution<int>(0, num_elements), rng);
auto const seed = std::random_device()();


class unordered_mapFixture : public celero::TestFixture
{
public:
	std::unordered_map<int,int> map;
	int key;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(seed);
		key = rand_int();

		for (int i = 0; i < num_elements; ++i)
		{
			map.emplace(i, rand_int());
		}
	}
};


class mapFixture : public celero::TestFixture
{
public:
	std::map<int, int> map;
	int key;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(seed);
		key = rand_int();

		for (int i = 0; i < num_elements; ++i)
		{
			map.emplace(i, rand_int());
		}
	}
};


BASELINE_F(unordered_map, find, unordered_mapFixture, g_samples, g_iterations)
{
	int result;
	auto iter = map.find(key);
	if(iter != map.end()) {
		result = iter->second;
		celero::DoNotOptimizeAway(result);
	}
}

BENCHMARK_F(unordered_map, count, unordered_mapFixture, g_samples, g_iterations)
{
	int result;
	if(map.count(key) > 0) {
		result = map.at(key);
		celero::DoNotOptimizeAway(result);
	}
}


BASELINE_F(map, find, mapFixture, g_samples, g_iterations)
{
	int result;
	auto iter = map.find(key);
	if(iter != map.end()) {
		result = iter->second;
		celero::DoNotOptimizeAway(result);
	}
}

BENCHMARK_F(map, count, mapFixture, g_samples, g_iterations)
{
	int result;
	if(map.count(key) > 0) {
		result = map.at(key);
		celero::DoNotOptimizeAway(result);
	}
}
