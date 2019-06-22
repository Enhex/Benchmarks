#include <celero/Celero.h>

#include <random>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 1000000;

std::mt19937 rng;
std::uniform_real_distribution<float> rng_dist(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());

auto random = [&](){
	return rng_dist(rng);
};


class A
{
public:
	A(float value) : array{value}, alias(array[0])
	{
	}

	float array[1];
	float& alias;
};

class B
{
public:
	B(float value) : array{value}
	{
	}

	float array[1];

	float& ref() { return array[0]; };
};

class AFixture : public celero::TestFixture
{
public:
	AFixture() : x(0)
	{
		rng.seed(0);
	}


	A x;

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		x.alias = random();
	}
};

class BFixture : public celero::TestFixture
{
public:
	BFixture() : x(0)
	{
		rng.seed(0);
	}


	B x;

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		x.array[0] = random();
	}
};


BASELINE_F(Setup, array, AFixture, g_samples, g_iterations)
{
	B x(0);
}


BENCHMARK_F(Setup, alias, AFixture, g_samples, g_iterations)
{
	A x(0);
}


BASELINE_F(Access, array_only, BFixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(x.array[0] + x.array[0]);
}


BENCHMARK_F(Access, array_only_ref, BFixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(x.ref() + x.ref());
}


BENCHMARK_F(Access, array, AFixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(x.array[0] + x.array[0]);
}


BENCHMARK_F(Access, alias, AFixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(x.alias + x.alias);
}