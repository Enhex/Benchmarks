#include <celero/Celero.h>
#include <boost/container/small_vector.hpp>
#include <vector>
using namespace boost::container;

CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 1000;



BASELINE(small_1, vector, g_samples, g_iterations)
{

	constexpr unsigned size = 1;
	std::vector<int> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}

BENCHMARK(small_1, vector_reserve, g_samples, g_iterations)
{

	constexpr unsigned size = 1;
	std::vector<int> v;
	v.reserve(size);
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}

BENCHMARK(small_1, small_vector, g_samples, g_iterations)
{
	constexpr unsigned size = 1;
	small_vector<int, size> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}




BASELINE(small_2, vector, g_samples, g_iterations)
{

	constexpr unsigned size = 2;
	std::vector<int> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}

BENCHMARK(small_2, vector_reserve, g_samples, g_iterations)
{

	constexpr unsigned size = 2;
	std::vector<int> v;
	v.reserve(size);
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}

BENCHMARK(small_2, small_vector, g_samples, g_iterations)
{
	constexpr unsigned size = 2;
	small_vector<int, size> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}




BASELINE(small_10, vector, g_samples, g_iterations)
{

	constexpr unsigned size = 10;
	std::vector<int> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}


BENCHMARK(small_10, vector_reserve, g_samples, g_iterations)
{

	constexpr unsigned size = 10;
	std::vector<int> v;
	v.reserve(size);
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}


BENCHMARK(small_10, small_vector, g_samples, g_iterations)
{
	constexpr unsigned size = 10;
	small_vector<int, size> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}




BASELINE(small_100, vector, g_samples, g_iterations)
{

	constexpr unsigned size = 100;
	std::vector<int> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}


BENCHMARK(small_100, vector_reserve, g_samples, g_iterations)
{

	constexpr unsigned size = 100;
	std::vector<int> v;
	v.reserve(size);
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}


BENCHMARK(small_100, small_vector, g_samples, g_iterations)
{
	constexpr unsigned size = 100;
	small_vector<int, size> v;
	for (unsigned i = 0; i < size; ++i)
		v.emplace_back(i);
}