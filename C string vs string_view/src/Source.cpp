#include <celero/Celero.h>
#include <string_view>
#include <string>
#include <cstring>

CELERO_MAIN

constexpr int g_samples = 1000;
constexpr int g_iterations = 10000;

using namespace std;

char cs1[] = "hello world hello world hello world hello world hello world hello world hello world hello world hello world";
char cs2[] = "hello world hello world hello world hello world hello world";
string_view sv1 = "hello world hello world hello world hello world hello world hello world hello world hello world hello world";
string_view sv2 = "hello world hello world hello world hello world hello world";
string s1 = "hello world hello world hello world hello world hello world hello world hello world hello world hello world";
string s2 = "hello world hello world hello world hello world hello world";

/* got same results with constepxr
constexpr char cs1[] = "hello world hello world hello world hello world hello world hello world hello world hello world hello world";
constexpr char cs2[] = "hello world hello world hello world hello world hello world";
constexpr string_view sv1 = "hello world hello world hello world hello world hello world hello world hello world hello world hello world"sv;
constexpr string_view sv2 = "hello world hello world hello world hello world hello world"sv;
*/


BASELINE(equal, C_string, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		strcmp(cs1, cs2) == 0
	);
}


BENCHMARK(equal, string_view, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		sv1 == sv2
	);
}


BENCHMARK(equal, str_view_c_str, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		sv1 == cs2
	);
}


BENCHMARK(equal, sv_c_literal, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		sv1 == "hello world hello world"
	);
}


BENCHMARK(equal, sv_sv_literal, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		sv1 == "hello world hello world"sv
	);
}


BENCHMARK(equal, string, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		s1 == s2
	);
}