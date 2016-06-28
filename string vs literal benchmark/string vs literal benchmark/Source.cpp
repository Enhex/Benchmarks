#include <celero/Celero.h>

#include <string>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 20;
constexpr int g_iterations = 1000;


std::string test(const std::string& str)
{
	return str + str;
}


BASELINE(Test, string, g_samples, g_iterations)
{
	std::string result;
	std::string str = "1234567890/qwertyuiop/asdfghjkl";

	for (size_t i = 0; i < 1000; ++i)
	{
		result = test(str);
	}
}


BENCHMARK(Test, literal, g_samples, g_iterations)
{
	std::string result;

	for (size_t i = 0; i < 1000; ++i)
	{
		// Slower beacause it creates a temporary string each time?
		result = test("1234567890/qwertyuiop/asdfghjkl");
	}
}