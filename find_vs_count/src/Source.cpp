#include <celero/Celero.h>

#include <map>
#include <unordered_map>

#include <random>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 1000;
constexpr int g_iterations = 75000;


std::mt19937 rng;
auto const seed = std::random_device()();


class baseFixture : public celero::TestFixture
{
public:
	int key;

	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = 16;

		for (int i = 1; i <= totalNumberOfTests; ++i)
			problemSpace.emplace_back(int64_t(pow(2, i)));

		return problemSpace;
	}
};

class unordered_mapFixture : public baseFixture
{
public:
	std::unordered_map<int,int> map;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(seed);
		auto rand_int = std::bind(std::uniform_int_distribution<int>(0, experimentValue.Value), rng);

		key = rand_int();

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
		{
			map.emplace(rand_int(), rand_int());
		}
	}
};


class mapFixture : public baseFixture
{
public:
	std::map<int, int> map;
	int key;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(seed);
		auto rand_int = std::bind(std::uniform_int_distribution<int>(0, experimentValue.Value), rng);

		key = rand_int();

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
		{
			map.emplace(rand_int(), rand_int());
		}
	}
};


BASELINE_F(unordered_map, find, unordered_mapFixture, g_samples, g_iterations)
{
	auto iter = map.find(key);
	if(iter != map.end()) {
		auto result = iter->second;
		celero::DoNotOptimizeAway(result);
	}
}

BENCHMARK_F(unordered_map, count, unordered_mapFixture, g_samples, g_iterations)
{
	if(map.count(key) > 0) {
		auto result = map.at(key);
		celero::DoNotOptimizeAway(result);
	}
}


BASELINE_F(map, find, mapFixture, g_samples, g_iterations)
{
	auto iter = map.find(key);
	if(iter != map.end()) {
		auto result = iter->second;
		celero::DoNotOptimizeAway(result);
	}
}

BENCHMARK_F(map, count, mapFixture, g_samples, g_iterations)
{
	if(map.count(key) > 0) {
		auto result = map.at(key);
		celero::DoNotOptimizeAway(result);
	}
}
