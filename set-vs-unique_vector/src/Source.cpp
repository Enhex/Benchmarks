#include <celero/Celero.h>

#include <random>
#include <limits>
#include <set>
#include <vector>
#include <algorithm>

#include <iostream>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
//CELERO_MAIN

constexpr int g_samples = 10;
constexpr int g_iterations = 2000;


std::mt19937 rng;
auto random_int = std::bind(std::uniform_int_distribution<int>(0, 10), rng); // using ints and limited range to get duplicates

size_t g_num_elements = 1000;
std::vector<int> g_int_elements;


int main(int argc, char** argv)
{
	// Create elements
	g_int_elements.reserve(g_num_elements);
	for (size_t i = 0; i < g_num_elements; ++i)
		g_int_elements.emplace_back(random_int());

	// Run
	celero::Run(argc, argv);
	return 0;
}



BASELINE(int_10_range_0_10, set, g_samples, g_iterations)
{
	std::set<int> set;

	for (size_t i = 0; i < 10; ++i)
		set.insert(g_int_elements[i]);

	// Just to make sure it works
	/*std::cout << std::endl;
	for (auto e : set)
		std::cout << e << "\n";*/
}


// 10
BENCHMARK(int_10_range_0_10, unique_vector, g_samples, g_iterations)
{
	std::vector<int> vec;

	for (size_t i = 0; i < 10; ++i)
		vec.emplace_back(g_int_elements[i]);

	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	// Just to make sure it works
	/*std::cout << std::endl;
	for(auto e : vec)
		std::cout << e << "\n";*/
}



// 100
BASELINE(int_100_range_0_10, set, g_samples, g_iterations)
{
	std::set<int> set;

	for (size_t i = 0; i < 100; ++i)
		set.insert(g_int_elements[i]);
}


BENCHMARK(int_100_range_0_10, unique_vector, g_samples, g_iterations)
{
	std::vector<int> vec;

	for (size_t i = 0; i < 100; ++i)
		vec.emplace_back(g_int_elements[i]);

	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}



// 1,000
BASELINE(int_1000_range_0_10, set, g_samples, g_iterations)
{
	std::set<int> set;

	for (size_t i = 0; i < 1000; ++i)
		set.insert(g_int_elements[i]);
}


BENCHMARK(int_1000_range_0_10, unique_vector, g_samples, g_iterations)
{
	std::vector<int> vec;

	for (size_t i = 0; i < 1000; ++i)
		vec.emplace_back(g_int_elements[i]);

	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}



// 10,000
BASELINE(int_10000_range_0_10, set, g_samples, g_iterations)
{
	std::set<int> set;

	for (size_t i = 0; i < 10000; ++i)
		set.insert(g_int_elements[i]);
}


BENCHMARK(int_10000_range_0_10, unique_vector, g_samples, g_iterations)
{
	std::vector<int> vec;

	for (size_t i = 0; i < 10000; ++i)
		vec.emplace_back(g_int_elements[i]);

	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}