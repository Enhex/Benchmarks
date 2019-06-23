#include <celero/Celero.h>

#include <string>
#include <random>
#include <limits>

#include <boost/random/taus88.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <pcg_random.hpp>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 10;
constexpr int g_iterations = 1000;
constexpr int g_loop = 10000;


// mt19937
std::mt19937 rng_mt19937;

std::uniform_int_distribution<int> distribution_int(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
std::uniform_int_distribution<long> distribution_long(std::numeric_limits<long>::min(), std::numeric_limits<long>::max());

auto random_mt19937_int() noexcept
{
	return distribution_int(rng_mt19937);
}

auto random_mt19937_long() noexcept
{
	return distribution_long(rng_mt19937);
}

// taus88
boost::random::taus88 rng_taus88;
boost::random::uniform_int_distribution<int> dist_taus88_int(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
boost::random::uniform_int_distribution<long> dist_taus88_long(std::numeric_limits<long>::min(), std::numeric_limits<long>::max());


int random_taus88_int() noexcept
{
	return dist_taus88_int(rng_taus88);
}
long random_taus88_long() noexcept
{
	return dist_taus88_long(rng_taus88);
}


// PCG
pcg32 pcg;

auto random_pcg_int() noexcept
{
	return distribution_int(pcg);
}

auto random_pcg_long() noexcept
{
	return distribution_long(pcg);
}


// WELL512
// http://www.lomont.org/Math/Papers/2008/Lomont_PRNG_2008.pdf
/* initialize state to random bits */
static unsigned long state[16];
/* init should also reset this to 0 */
static unsigned int well_index = 0;
/* return 32 bit random number */
unsigned long WELLRNG512(void)
{
	unsigned long a, b, c, d;
	a = state[well_index];
	c = state[(well_index + 13) & 15];
	b = a^c ^ (a << 16) ^ (c << 15);
	c = state[(well_index + 9) & 15];
	c ^= (c >> 11);
	a = state[well_index] = b^c;
	d = a ^ ((a << 5) & 0xDA442D24UL);
	well_index = (well_index + 15) & 15;
	a = state[well_index];
	state[well_index] = a^b^d ^ (a << 2) ^ (b << 18) ^ (c << 28);
	return state[well_index];
}


// intel fastrand
// https://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor
static unsigned int g_fastrand_seed;
inline int fastrand() {
	g_fastrand_seed = (214013 * g_fastrand_seed + 2531011);
	return (g_fastrand_seed >> 16) & 0x7FFF;
}


// xorshift+
// https://en.wikipedia.org/wiki/Xorshift
/* The state must be seeded so that it is not everywhere zero. */
uint64_t s[2];

uint64_t xorshift128plus(void) {
	uint64_t x = s[0];
	uint64_t const y = s[1];
	s[0] = y;
	x ^= x << 23; // a
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26); // b, c
	return s[1] + y;
}


//#define DONT_OPTIMIIZE


// int
BASELINE(int, rand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(rand());
#else
		rand();
#endif
}


BENCHMARK(int, mt19937, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(random_mt19937_int());
#else
		random_mt19937_int();
#endif
}


BENCHMARK(int, WELL512, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(static_cast<int>(WELLRNG512()));// using long
#else
		static_cast<int>(WELLRNG512());// using long
#endif
}


BENCHMARK(int, taus88, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(random_taus88_int());
#else
		random_taus88_int();
#endif
}


BENCHMARK(int, intel_fastrand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(fastrand());
#else
		fastrand();
#endif
}


BENCHMARK(int, xorshiftplus, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(static_cast<int>(xorshift128plus()));// using uint64_t
#else
		static_cast<int>(xorshift128plus());
#endif
}


BENCHMARK(int, pcg, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(random_pcg_int());
#else
		random_pcg_int();
#endif
}


// long
BASELINE(long, rand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway((static_cast<long>(rand()) << (sizeof(int) * 8 - 1)) | rand());
#else
		(static_cast<long>(rand()) << (sizeof(int) * 8 - 1)) | rand();
#endif
}


BENCHMARK(long, mt19937, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(random_mt19937_long());
#else
		random_mt19937_long();
#endif
}


BENCHMARK(long, WELL512, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(WELLRNG512());
#else
		WELLRNG512();
#endif
}


BENCHMARK(long, taus88, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(random_taus88_long());
#else
		random_taus88_long();
#endif
}


BENCHMARK(long, intel_fastrand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway((static_cast<long>(fastrand()) << (sizeof(int) * 8 - 1)) | fastrand());
#else
		(static_cast<long>(fastrand()) << (sizeof(int) * 8 - 1)) | fastrand();
#endif
}


BENCHMARK(long, xorshiftplus, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(xorshift128plus());
#else
		xorshift128plus();
#endif
}


BENCHMARK(long, pcg, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
#ifdef DONT_OPTIMIIZE
		celero::DoNotOptimizeAway(random_pcg_long());
#else
		random_pcg_long();
#endif
}