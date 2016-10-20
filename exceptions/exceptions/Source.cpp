#include <celero/Celero.h>

#include <random>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 150000;

std::mt19937 rng;
//auto random = std::bind(std::uniform_real_distribution<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()), rng);
auto random = std::bind(std::uniform_int_distribution<int>(1, std::numeric_limits<int>::max()), rng);

bool divide_check(int& a, int b)
{
	if(b == 0)
		return false;
	a /= b;
	return true;
}

void divide_exception(int& a, int b)
{
	if (b == 0)
		throw;
	a /= b;
}

class BaseFixture : public celero::TestFixture
{
public:
	BaseFixture()
	{
		rng.seed(0);
	}
};


BASELINE_F(1_check, if_check, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	if (divide_check(a, b))
		a += b;
	else
		b += a;
}


BENCHMARK_F(1_check, exception, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	try
	{
		divide_exception(a, b);
		a += b;
	}
	catch(...)
	{
		b += a;
	}
}


BASELINE_F(2_check, if_check, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	if (divide_check(a, b) &&
		divide_check(a, b))
		a += b;
	else
		b += a;
}


BENCHMARK_F(2_check, exception, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	try
	{
		divide_exception(a, b);
		divide_exception(a, b);
		a += b;
	}
	catch (...)
	{
		b += a;
	}
}


BASELINE_F(4_check, if_check, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	if (divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b))
		a += b;
	else
		b += a;
}


BENCHMARK_F(4_check, exception, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	try
	{
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		a += b;
	}
	catch (...)
	{
		b += a;
	}
}


BASELINE_F(8_check, if_check, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	if (divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b))
		a += b;
	else
		b += a;
}


BENCHMARK_F(8_check, exception, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	try
	{
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		a += b;
	}
	catch (...)
	{
		b += a;
	}
}


BASELINE_F(16_check, if_check, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	if (divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b))
		a += b;
	else
		b += a;
}


BENCHMARK_F(16_check, exception, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	try
	{
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		a += b;
	}
	catch (...)
	{
		b += a;
	}
}


BASELINE_F(32_check, if_check, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	if (divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b) &&
		divide_check(a, b))
		a += b;
	else
		b += a;
}


BENCHMARK_F(32_check, exception, BaseFixture, g_samples, g_iterations)
{
	int a = random();
	int b = random();
	try
	{
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		divide_exception(a, b);
		a += b;
	}
	catch (...)
	{
		b += a;
	}
}