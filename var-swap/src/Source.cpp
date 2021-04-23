#include <celero/Celero.h>

#include <array>
#include <random>
#include <limits>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 1000;
constexpr int g_iterations = 10000;

std::mt19937 rng;
auto rand_int = std::bind(std::uniform_int_distribution<int>(std::numeric_limits<int>::min() / 2, std::numeric_limits<int>::max() / 2), rng);


class intFixture : public celero::TestFixture
{
public:
	using type = int;
	type a;
	type b;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		rng.seed(0);

		a = rand_int();
		b = rand_int();
	}
};


BASELINE_F(swap, 3_vars, intFixture, g_samples, g_iterations)
{
	auto temp = a;
	a = b;
	b = temp;
}


BENCHMARK_F(swap, add, intFixture, g_samples, g_iterations)
{
	a = a + b;
	b = a - b;
	a = a - b;
}


BENCHMARK_F(swap, XOR, intFixture, g_samples, g_iterations)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}