#include <celero/Celero.h>

#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include <random>
#include <limits>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 2;
constexpr int g_iterations = 50;

std::mt19937 rng;
auto rand_int = std::bind(std::uniform_int_distribution<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()), rng);


struct baseFixture : celero::TestFixture
{
	std::vector<int> find_elements;

	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = 20;

		for (int i = 1; i <= totalNumberOfTests; ++i)
			problemSpace.emplace_back(int64_t(pow(2, i)));

		return problemSpace;
	}
};


struct unordered_setFixture : baseFixture
{
	std::unordered_set<int> set;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(0);

		find_elements.reserve((size_t)experimentValue.Value);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
		{
			auto const element = rand_int();
			set.emplace(element);
			find_elements.emplace_back(element);
		}

		std::shuffle(find_elements.begin(), find_elements.end(), rng);
	}
};

struct unordered_setReservedFixture : baseFixture
{
	std::unordered_set<int> set;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(0);

		set.reserve((size_t)experimentValue.Value); // Might affect performance if it causes contiguous memory, which isn't the common use case for unordered_set
		find_elements.reserve((size_t)experimentValue.Value);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
		{
			auto const element = rand_int();
			set.emplace(element);
			find_elements.emplace_back(element);
		}

		std::shuffle(find_elements.begin(), find_elements.end(), rng);
	}
};


struct setFixture : baseFixture
{
	std::set<int> set;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(0);

		//set.reserve((size_t)experimentValue); // Might affect performance if it causes contiguous memory, which isn't the common use case for unordered_set
		find_elements.reserve((size_t)experimentValue.Value);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
		{
			auto const element = rand_int();
			set.emplace(element);
			find_elements.emplace_back(element);
		}

		std::shuffle(find_elements.begin(), find_elements.end(), rng);
	}
};

struct setLimitedFixture : setFixture
{
	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = 17;

		for (int i = 1; i <= totalNumberOfTests; ++i)
			problemSpace.emplace_back(int64_t(pow(2, i)), uint64_t(0));

		return problemSpace;
	}
};


struct vectorFixture : baseFixture
{
	std::vector<int> vec;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(0);

		vec.reserve((size_t)experimentValue.Value); // vector is memory contiguous, so no performance change
		find_elements.reserve((size_t)experimentValue.Value);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
		{
			auto const element = rand_int();
			vec.emplace_back(element);
			find_elements.emplace_back(element);
		}

		std::shuffle(find_elements.begin(), find_elements.end(), rng);
	}
};

struct vectorPresortedFixture : vectorFixture
{
	virtual void setUp(int64_t experimentValue)
	{
		vectorFixture::setUp(experimentValue);
		std::sort(vec.begin(), vec.end());
	}
};

struct vectorLimitedFixture : vectorFixture
{
	virtual std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = 13;

		for (int i = 1; i <= totalNumberOfTests; ++i)
			problemSpace.emplace_back(int64_t(pow(2, i)), uint64_t(0));

		return problemSpace;
	}
};



BASELINE_F(Search, unordered_set, unordered_setFixture, g_samples, g_iterations)
{
	for (auto& e : find_elements) {
		auto result = set.find(e);
		celero::DoNotOptimizeAway(result);
	}
}


BENCHMARK_F(Search, unordered_set_reservred, unordered_setReservedFixture, g_samples, g_iterations)
{
	for (auto& e : find_elements) {
		auto result = set.find(e);
		celero::DoNotOptimizeAway(result);
	}
}


// Using limited fixture because it takes too long
BENCHMARK_F(Search, set_find, setLimitedFixture, g_samples, g_iterations)
{
	for (auto& e : find_elements) {
		auto result = set.find(e);
		celero::DoNotOptimizeAway(result);
	}
}


// Using limited fixture because it takes too long
BENCHMARK_F(Search, set_lower_bound, setLimitedFixture, g_samples, g_iterations)
{
	for (auto& e : find_elements) {
		auto result = set.lower_bound(e);
		celero::DoNotOptimizeAway(result);
	}
}


// Using limited fixture because it takes too long
BENCHMARK_F(Search, vector_find, vectorLimitedFixture, g_samples, g_iterations)
{
	for (auto& e : find_elements) {
		auto result = std::find(vec.begin(), vec.end(), e);
		celero::DoNotOptimizeAway(result);
	}
}


BENCHMARK_F(Search, vector_lower_bound, vectorFixture, g_samples, g_iterations)
{
	std::sort(vec.begin(), vec.end());

	for (auto& e : find_elements) {
		auto result = std::lower_bound(vec.begin(), vec.end(), e);
		celero::DoNotOptimizeAway(result);
	}
}


BENCHMARK_F(Search, vector_lower_bound_presorted, vectorPresortedFixture, g_samples, g_iterations)
{
	for (auto& e : find_elements) {
		auto result = std::lower_bound(vec.begin(), vec.end(), e);
		celero::DoNotOptimizeAway(result);
	}
}