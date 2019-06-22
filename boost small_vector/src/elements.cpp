#include <celero/Celero.h>
#include <boost\container\small_vector.hpp>
#include <vector>
using namespace boost::container;

CELERO_MAIN

constexpr int g_samples = 30;
constexpr int g_iterations = 10000;


class Fixture : public celero::TestFixture
{
public:
	unsigned factor;

	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		constexpr int64_t totalNumberOfTests = 256;

		for (int64_t i = 1; i <= totalNumberOfTests; ++i)
			problemSpace.emplace_back(i);

		return problemSpace;
	}

	virtual void setUp(int64_t experimentValue)
	{
		factor = (decltype(factor))experimentValue;
	}
};


BASELINE_F(size_10, vector, Fixture, g_samples, g_iterations)
{

	constexpr unsigned size = 10;
	const unsigned count = size * factor;
	std::vector<int> v;
	for (unsigned i = 0; i < count; ++i)
		v.emplace_back(i);
}


BENCHMARK_F(size_10, vector_reserve, Fixture, g_samples, g_iterations)
{

	constexpr unsigned size = 10;
	const unsigned count = size * factor;
	std::vector<int> v;
	v.reserve(size);
	for (unsigned i = 0; i < count; ++i)
		v.emplace_back(i);
}


BENCHMARK_F(size_10, small_vector, Fixture, g_samples, g_iterations)
{
	constexpr unsigned size = 10;
	const unsigned count = size * factor;
	small_vector<int, size> v;
	for (unsigned i = 0; i < count; ++i)
		v.emplace_back(i);
}