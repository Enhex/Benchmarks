#include <celero/Celero.h>
#include <tuple>

CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 2000;


std::tuple<int> tuple_return()
{
	int x = 2;
	return std::make_tuple(x);
}

int regular_return()
{
	int x = 2;
	return x;
}


BASELINE(single_return, single, g_samples, g_iterations)
{
	regular_return();
}


BENCHMARK(single_return, tuple, g_samples, g_iterations)
{
	tuple_return();
}




std::tuple<int> tuple_return_rvalue()
{
	return std::make_tuple(2);
}

int regular_return_rvalue()
{
	return 2;
}


BASELINE(single_return_rvalue, single, g_samples, g_iterations)
{
	regular_return_rvalue();
}


BENCHMARK(single_return_rvalue, tuple, g_samples, g_iterations)
{
	tuple_return_rvalue();
}




std::tuple<int, float> tuple2_return()
{
	int x = 2;
	float y = 2.5f;
	return std::make_tuple(x, y);
}

void reference2_return(int& x, float& y)
{
	x = 2;
	y = 2.5f;
}


BASELINE(multi_return_2, reference, g_samples, g_iterations)
{
	int x;
	float y;
	reference2_return(x, y);
}


BENCHMARK(multi_return_2, tuple, g_samples, g_iterations)
{
	auto[x,y] = tuple2_return();
}