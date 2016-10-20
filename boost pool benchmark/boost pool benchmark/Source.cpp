#include <celero/Celero.h>

#include <boost\pool\pool_alloc.hpp>
#include <set>
#include <unordered_set>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 2;
constexpr int g_iterations = 1000;


BASELINE(Vector, std, g_samples, g_iterations)
{
	std::vector<int> v;
	for (int r = 0; r < 100; ++r)
	{
		for (int i = 0; i < 100; ++i)
			v.push_back(13);
		v.clear();
	}
}


BENCHMARK(Vector, fast_pool_allocator, g_samples, g_iterations)
{
	{
		std::vector<int, boost::pool_allocator<int>> v;
		for (int r = 0; r < 100; ++r)
		{
			for (int i = 0; i < 100; ++i)
				v.push_back(13);
			v.clear();
		}
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BENCHMARK(Vector, boost_pool_allocator, g_samples, g_iterations)
{
	{
		std::vector<int, boost::fast_pool_allocator<int>> v;
		for (int r = 0; r < 100; ++r)
		{
			for (int i = 0; i < 100; ++i)
				v.push_back(13);
			v.clear();
		}
	}

	boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::release_memory();
}


BASELINE(Set, std, g_samples, g_iterations)
{
	std::set<int> v;
	for (int r = 0; r < 100; ++r)
	{
		for (int i = 0; i < 100; ++i)
			v.insert(13);
		v.clear();
	}
}


BENCHMARK(Set, pool_allocator, g_samples, g_iterations)
{
	{
		std::set<int, std::less<int>, boost::pool_allocator<int>> v;
		for (int r = 0; r < 100; ++r)
		{
			for (int i = 0; i < 100; ++i)
				v.insert(13);
			v.clear();
		}
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BASELINE(unordered_set, std, g_samples, g_iterations)
{
	std::unordered_set<int> v;
	for (int r = 0; r < 100; ++r)
	{
		for (int i = 0; i < 100; ++i)
			v.insert(13);
		v.clear();
	}
}


BENCHMARK(unordered_set, pool_allocator, g_samples, g_iterations)
{
	std::unordered_set<int, std::hash<int>, std::equal_to<int>, boost::pool_allocator<int>> v;
	for (int r = 0; r < 100; ++r)
	{
		for (int i = 0; i < 100; ++i)
			v.insert(13);
		v.clear();
	}

	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::release_memory();
}


BENCHMARK(unordered_set, fast_pool_allocator, g_samples, g_iterations)
{
	{
		std::unordered_set<int, std::hash<int>, std::equal_to<int>, boost::fast_pool_allocator<int>> v;
		for (int r = 0; r < 100; ++r)
		{
			for (int i = 0; i < 100; ++i)
				v.insert(13);
			v.clear();
		}
	}

	boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::release_memory();
}