#include <celero/Celero.h>

#include <string>
#include <random>
#include <algorithm>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 20;
constexpr int g_iterations = 1000000;

std::mt19937 rng;
auto random = std::bind(std::uniform_int_distribution<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()), rng);
constexpr size_t g_num_elements = 100;
std::vector<int> g_elements;


//int main(int argc, char** argv)
//{
//	// Create elements
//	g_elements.reserve(g_num_elements);
//	for (size_t i = 0; i < g_num_elements; ++i)
//		g_elements.emplace_back(random());
//
//	// Run
//	celero::Run(argc, argv);
//	return 0;
//}

class baseFixture : public celero::TestFixture
{
public:
	int a, b;

	virtual void setUp(int64_t experimentValue)
	{
		a = random();
		b = random();
	}
};


BASELINE_F(MinMax, naive, baseFixture, g_samples, g_iterations)
{
	std::pair<int, int> result;
	if (a < b)
	{
		result.first = a;
		result.second = b;
	}
	else
	{
		result.first = b;
		result.second = a;
	}
}


BENCHMARK_F(MinMax, std_minmax, baseFixture, g_samples, g_iterations)
{
	auto result = std::minmax(a, b);
}