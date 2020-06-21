#include <celero/Celero.h>

#include <new>

///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 30;
constexpr int g_iterations = 100;

constexpr int num_elements = 20000;
constexpr int gap_size = std::hardware_destructive_interference_size;

using element_type = int;

// array of structures
template<int bytes>
struct AOS
{
	element_type x;
	char gap[bytes];
	element_type y;
};

AOS<gap_size> aos[num_elements];


// structure of arrays
template<int bytes>
struct SOA
{
	element_type x[num_elements];
	char gap[bytes];
	element_type y[num_elements];
};

SOA<gap_size> soa;




// array of structures
struct AOS_NG
{
	element_type x;
	element_type y;
};

AOS_NG aos_no_gap[num_elements];


// structure of arrays
struct SOA_NG
{
	element_type x[num_elements];
	element_type y[num_elements];
};


SOA_NG soa_no_gap;


BASELINE(Prefetcher, AOS, g_samples, g_iterations)
{
	auto diff = 0;
	for (auto& e : aos) {
		diff -= e.x;
	}
	for (auto& e : aos) {
		diff -= e.y;
	}
	celero::DoNotOptimizeAway(diff);
}


BENCHMARK(Prefetcher, SOA, g_samples, g_iterations)
{
	auto diff = 0;
	for (auto& x : soa.x) {
		diff -= x;
	}
	for (auto& y : soa.y) {
		diff -= y;
	}
	celero::DoNotOptimizeAway(diff);
}


BASELINE(Prefetcher_no_gap, AOS, g_samples, g_iterations)
{
	auto diff = 0;
	for (auto& e : aos_no_gap) {
		diff -= e.x;
	}
	for (auto& e : aos_no_gap) {
		diff -= e.y;
	}
	celero::DoNotOptimizeAway(diff);
}


BENCHMARK(Prefetcher_no_gap, SOA, g_samples, g_iterations)
{
	auto diff = 0;
	for (auto& x : soa_no_gap.x) {
		diff -= x;
	}
	for (auto& y : soa_no_gap.y) {
		diff -= y;
	}
	celero::DoNotOptimizeAway(diff);
}
