#include <celero/Celero.h>
#include <fmt/format.h>
#include <iostream>
#include <limits>
#include <random>

CELERO_MAIN

constexpr int g_samples = 50;
constexpr int g_iterations = 3000;

std::random_device rd;
std::mt19937 rng(rd());
auto distribution_int = std::uniform_int_distribution<>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
auto random_int = [] {
	return distribution_int(rng);
};

//auto distribution_float = std::uniform_real_distribution<float>(std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max());
auto distribution_float = std::uniform_real_distribution<float>(-1000000, 1000000);
auto random_float = [] {
	return distribution_float(rng);
};


BASELINE(str_var, cout, g_samples, g_iterations)
{
	std::string x = "some string literal";
	std::cout << x;
}

BENCHMARK(str_var, printf, g_samples, g_iterations)
{
	std::string x = "some string literal";
	std::printf("%s", x.c_str());
}

BENCHMARK(str_var, fwrite, g_samples, g_iterations)
{
	std::string x = "some string literal";
	std::fwrite(x.data(), 1, x.size(), stdout);
}

BENCHMARK(str_var, fmt, g_samples, g_iterations)
{
	std::string x = "some string literal";
	fmt::print(x);
}


BASELINE(str_lit, cout, g_samples, g_iterations)
{
	std::cout << "some string literal";
}

BENCHMARK(str_lit, printf, g_samples, g_iterations)
{
	std::printf("some string literal");
}

BENCHMARK(str_lit, fmt, g_samples, g_iterations)
{
	fmt::print("some string literal");
}

BENCHMARK(str_lit, puts, g_samples, g_iterations)
{
	std::puts("some string literal");
}


BASELINE(str_lit_L, cout, g_samples, g_iterations)
{
	std::cout << "some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

BENCHMARK(str_lit_L, printf, g_samples, g_iterations)
{
	std::printf("some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

BENCHMARK(str_lit_L, fmt, g_samples, g_iterations)
{
	fmt::print("some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}


BASELINE(str_lit_LL, cout, g_samples, g_iterations)
{
	std::cout << "some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
}

BENCHMARK(str_lit_LL, printf, g_samples, g_iterations)
{
	std::printf("some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
}

BENCHMARK(str_lit_LL, fmt, g_samples, g_iterations)
{
	fmt::print("some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ some very very long string literal 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
}