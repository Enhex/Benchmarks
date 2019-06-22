#define BOOST_SIMD_ASSUME_SSE4_2

#include <algorithm>
#include <array>
#include <boost/simd/algorithm/find.hpp>
#include <boost/simd/algorithm/find_if_not.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/memory.hpp>
#include <boost/simd/pack.hpp>
#include <celero/Celero.h>
#include <numeric>
#include <vector>
namespace bs = boost::simd;
using TestType = float;
using pack_t = bs::pack<TestType>;

//CELERO_MAIN
int main(int argc, char** argv)
{
	std::cout << pack_t::static_size << std::endl;
	celero::Run(argc, argv);
	return 0;
}

constexpr int g_samples = 200;
constexpr int g_iterations = 10000;

const std::string str = "                                                                                                                                               1";


BASELINE(add_multi, simd, g_samples, g_iterations)
{
	pack_t iter_pack;
	std::iota(iter_pack.begin(), iter_pack.begin() + pack_t::static_size, TestType(0));
	iter_pack = pack_t(iter_pack + iter_pack) * 2;
	//std::cout << iter_pack << std::endl;
}


BENCHMARK(add_multi, loop_vector, g_samples, g_iterations)
{
	std::vector<TestType> data(pack_t::static_size);
	std::iota(data.begin(), data.begin() + pack_t::static_size, TestType(0));
	for (size_t i = 0; i < data.size(); ++i) {
		data[i] = (data[i] + data[i]) * 2;
		//std::cout << data[i] << std::endl;
	}
}



BENCHMARK(add_multi, loop_array, g_samples, g_iterations)
{
	std::array<TestType, pack_t::static_size> data;
	std::iota(data.begin(), data.begin() + pack_t::static_size, TestType(0));
	for (size_t i = 0; i < data.size(); ++i) {
		data[i] = (data[i] + data[i]) * 2;
		//std::cout << data[i] << std::endl;
	}
}


BASELINE(find, simd, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(bs::find(str.data(), str.data() + str.size(), '1'));
}

BENCHMARK(find, iter_while, g_samples, g_iterations)
{
	auto iter = str.begin();
	while (*iter != '1')
		++iter;
	celero::DoNotOptimizeAway(iter);
}

BENCHMARK(find, string, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(str.find('1'));
}

BENCHMARK(find, std_find, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(std::find(str.begin(), str.end(), '1'));
}



BASELINE(find_not, simd, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(bs::find_if_not(str.data(), str.data() + str.size(), [](auto& c) {return c == ' '; }));
}

BENCHMARK(find_not, simd_it_it, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(bs::find_if_not(&*str.begin(), &*str.end(), [](auto& c) {return c == ' '; }));
}
BENCHMARK(find_not, simd_da_it, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(bs::find_if_not(str.data(), &*str.end(), [](auto& c) {return c == ' '; }));
}

BENCHMARK(find_not, iter_while, g_samples, g_iterations)
{
	auto iter = str.begin();
	while (*iter == ' ')
		++iter;
	celero::DoNotOptimizeAway(iter);
}

BENCHMARK(find_not, iter_for, g_samples, g_iterations)
{
	auto iter = str.begin();
	for (; *iter == ' '; ++iter);
	celero::DoNotOptimizeAway(iter);
}

BENCHMARK(find_not, string, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(str.find_first_not_of(' '));
}

BENCHMARK(find_not, std_find, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(std::find_if_not(str.begin(), str.end(), [](auto& c) {return c == ' '; }));
}