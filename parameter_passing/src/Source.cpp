#include <celero/Celero.h>

#include <array>
#include <cstdint>

CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 1000000;


template<typename T>
void f_copy(T x)
{
}
template<typename T>
void f_ref(T& x)
{
}


BASELINE(int8, ref, g_samples, g_iterations)
{
	int8_t x;
	f_ref(x);
}
BENCHMARK(int8, copy, g_samples, g_iterations)
{
	int8_t x;
	f_copy(x);
}


BASELINE(int16, ref, g_samples, g_iterations)
{
	int16_t x;
	f_ref(x);
}
BENCHMARK(int16, copy, g_samples, g_iterations)
{
	int16_t x;
	f_copy(x);
}


BASELINE(int32, ref, g_samples, g_iterations)
{
	int32_t x;
	f_ref(x);
}
BENCHMARK(int32, copy, g_samples, g_iterations)
{
	int32_t x;
	f_copy(x);
}


BASELINE(int64, ref, g_samples, g_iterations)
{
	int64_t x;
	f_ref(x);
}
BENCHMARK(int64, copy, g_samples, g_iterations)
{
	int64_t x;
	f_copy(x);
}


BASELINE(array_1, ref, g_samples, g_iterations)
{
	std::array<char,1> x;
	f_ref(x);
}
BENCHMARK(array_1, copy, g_samples, g_iterations)
{
	std::array<char,1> x;
	f_copy(x);
}


BASELINE(array_10, ref, g_samples, g_iterations)
{
	std::array<char,10> x;
	f_ref(x);
}
BENCHMARK(array_10, copy, g_samples, g_iterations)
{
	std::array<char,10> x;
	f_copy(x);
}


BASELINE(array_100, ref, g_samples, g_iterations)
{
	std::array<char,100> x;
	f_ref(x);
}
BENCHMARK(array_100, copy, g_samples, g_iterations)
{
	std::array<char,100> x;
	f_copy(x);
}


BASELINE(array_1000, ref, g_samples, g_iterations)
{
	std::array<char,1000> x;
	f_ref(x);
}
BENCHMARK(array_1000, copy, g_samples, g_iterations)
{
	std::array<char,1000> x;
	f_copy(x);
}


BASELINE(array_10000, ref, g_samples, g_iterations)
{
	std::array<char,10000> x;
	f_ref(x);
}
BENCHMARK(array_10000, copy, g_samples, g_iterations)
{
	std::array<char,10000> x;
	f_copy(x);
}
