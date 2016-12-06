#include <celero/Celero.h>

#include <random>

#ifndef WIN32
#include <cmath>
#include <cstdlib>
#endif

std::mt19937 rng;
std::uniform_int_distribution<int> distribution(-1024, 1024);
auto rand_int = std::bind(distribution, rng);

unsigned g_samples = 10;
unsigned g_iterations = 1;// 0000;


// Accessing a member variable is a good use case for using a lambda since iterators can't be used.
class A
{
public:
	int x;
};

constexpr size_t array_size = 10000;
int int_array[array_size];
A A_array[array_size];


int main(int argc, char** argv)
{
	// Populate the arrays with random numbers
	for (size_t i = 0; i < array_size; ++i)
	{
		int_array[i] = rand_int();
		A_array[i].x = rand_int();
	}

	celero::Run(argc, argv);
	return 0;
}


// General implementation with std::function
int sum_function(std::function<int(size_t)> get_element)
{
	int sum = 0;

	for (size_t i = 0; i < array_size; ++i)
		sum += get_element(i);

	return sum;
}


// General implementation with template parameter
template<typename Accessor>
int sum_template(Accessor get_element)
{
	int sum = 0;

	for (size_t i = 0; i < array_size; ++i)
		sum += get_element(i);

	return sum;
}


// Manual implementation to access int array
int sum_manual_int()
{
	int sum = 0;

	for (size_t i = 0; i < array_size; ++i)
		sum += int_array[i];

	return sum;
}


// Manual implementation to access A array x member
int sum_manual_A()
{
	int sum = 0;

	for (size_t i = 0; i < array_size; ++i)
		sum += A_array[i].x;

	return sum;
}



// int
BASELINE(version_int, manual, g_samples, g_iterations)
{
	int sum = sum_manual_int();
}


BENCHMARK(version_int, std_function, g_samples, g_iterations)
{
	int sum = sum_function([](const size_t i) {return int_array[i]; });
}


BENCHMARK(version_int, template, g_samples, g_iterations)
{
	int sum = sum_template([](const size_t i) {return int_array[i]; });
}



// A
BASELINE(version_member, manual, g_samples, g_iterations)
{
	int sum = sum_manual_A();
}


BENCHMARK(version_member, std_function, g_samples, g_iterations)
{
	int sum = sum_function([](const size_t i) {return A_array[i].x; });
}


BENCHMARK(version_member, template, g_samples, g_iterations)
{
	int sum = sum_template([](const size_t i) {return A_array[i].x; });
}
