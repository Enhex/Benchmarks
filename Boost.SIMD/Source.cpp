#include <celero/Celero.h>
#include <vector>
#include <numeric>
#include <boost\simd\pack.hpp>
#include <boost/simd/memory.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/store.hpp>
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

constexpr int g_samples = 100;
constexpr int g_iterations = 1000;


BASELINE(group, simd, g_samples, g_iterations)
{
	pack_t iter_pack;
	std::iota(iter_pack.begin(), iter_pack.begin() + pack_t::static_size, TestType(0));
	iter_pack = pack_t(iter_pack + iter_pack) * 2;
	//std::cout << iter_pack << std::endl;
}


BENCHMARK(group, loop, g_samples, g_iterations)
{
	std::vector<TestType> data(pack_t::static_size);
	std::iota(data.begin(), data.begin() + pack_t::static_size, TestType(0));
	for (size_t i = 0; i < data.size(); ++i) {
		data[i] = (data[i] + data[i]) * 2;
		//std::cout << data[i] << std::endl;
	}
}