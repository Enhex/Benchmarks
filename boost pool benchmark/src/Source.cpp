#include <celero/Celero.h>

#include <boost\pool\pool_alloc.hpp>
#include <set>
#include <unordered_set>
#include <list>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 3;
constexpr int g_iterations = 500;

constexpr int num_resets = 10;
constexpr int num_elements = 1000;

BASELINE(Vector, std, g_samples, g_iterations)
{
	std::vector<int> v;
	for (int r = 0; r < num_resets; ++r)
	{
		for (int i = 0; i < num_elements; ++i)
			v.emplace_back(i);
		v.clear();
		celero::DoNotOptimizeAway(v);
	}
}


BENCHMARK(Vector, fast_pool_allocator, g_samples, g_iterations)
{
	{
		std::vector<int, boost::pool_allocator<int>> v;
		for (int r = 0; r < num_resets; ++r)
		{
			for (int i = 0; i < num_elements; ++i)
				v.emplace_back(i);
			v.clear();
			celero::DoNotOptimizeAway(v);
		}
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BENCHMARK(Vector, boost_pool_allocator, g_samples, g_iterations)
{
	{
		std::vector<int, boost::fast_pool_allocator<int>> v;
		for (int r = 0; r < num_resets; ++r)
		{
			for (int i = 0; i < num_elements; ++i)
				v.emplace_back(i);
			v.clear();
			celero::DoNotOptimizeAway(v);
		}
	}

	boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::release_memory();
}


BASELINE(Set, std, g_samples, g_iterations)
{
	std::set<int> v;
	for (int r = 0; r < num_resets; ++r)
	{
		for (int i = 0; i < num_elements; ++i)
			v.insert(i);
		v.clear();
		celero::DoNotOptimizeAway(v);
	}
}


BENCHMARK(Set, pool_allocator, g_samples, g_iterations)
{
	{
		std::set<int, std::less<int>, boost::pool_allocator<int>> v;
		for (int r = 0; r < num_resets; ++r)
		{
			for (int i = 0; i < num_elements; ++i)
				v.insert(i);
			v.clear();
			celero::DoNotOptimizeAway(v);
		}
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BASELINE(unordered_set, std, g_samples, g_iterations)
{
	std::unordered_set<int> v;
	for (int r = 0; r < num_resets; ++r)
	{
		for (int i = 0; i < num_elements; ++i)
			v.insert(i);
		v.clear();
		celero::DoNotOptimizeAway(v);
	}
}


BENCHMARK(unordered_set, pool_allocator, g_samples, g_iterations)
{
	std::unordered_set<int, std::hash<int>, std::equal_to<int>, boost::pool_allocator<int>> v;
	for (int r = 0; r < num_resets; ++r)
	{
		for (int i = 0; i < num_elements; ++i)
			v.insert(i);
		v.clear();
		celero::DoNotOptimizeAway(v);
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BENCHMARK(unordered_set, fast_pool_allocator, g_samples, g_iterations)
{
	{
		std::unordered_set<int, std::hash<int>, std::equal_to<int>, boost::fast_pool_allocator<int>> v;
		for (int r = 0; r < num_resets; ++r)
		{
			for (int i = 0; i < num_elements; ++i)
				v.insert(i);
			v.clear();
			celero::DoNotOptimizeAway(v);
		}
	}

	boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::release_memory();
}


BASELINE(list, std, g_samples, g_iterations)
{
	std::list<int> v;
	for (int r = 0; r < num_resets; ++r)
	{
		for (int i = 0; i < num_elements; ++i)
			v.emplace_back(i);
		v.clear();
		celero::DoNotOptimizeAway(v);
	}
}


BENCHMARK(list, pool_allocator, g_samples, g_iterations)
{
	std::list<int, boost::pool_allocator<int>> v;
	for (int r = 0; r < num_resets; ++r)
	{
		for (int i = 0; i < num_elements; ++i)
			v.emplace_back(i);
		v.clear();
		celero::DoNotOptimizeAway(v);
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BENCHMARK(list, fast_pool_allocator, g_samples, g_iterations)
{
	{
		std::list<int, boost::fast_pool_allocator<int>> v;
		for (int r = 0; r < num_resets; ++r)
		{
			for (int i = 0; i < num_elements; ++i)
				v.emplace_back(i);
			v.clear();
			celero::DoNotOptimizeAway(v);
		}
	}

	boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::release_memory();
}