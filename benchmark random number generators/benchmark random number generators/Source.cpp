#include <celero/Celero.h>

#include <string>
#include <random>
#include <limits>

#include <boost\random\taus88.hpp>
#include <boost\random\uniform_int_distribution.hpp>


///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 10;
constexpr int g_iterations = 2000;
constexpr int g_loop = 10000;


std::mt19937 rng_mt19937;
auto random_mt19937_int = std::bind(std::uniform_int_distribution<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()), rng_mt19937);
auto random_mt19937_long = std::bind(std::uniform_int_distribution<long>(std::numeric_limits<long>::min(), std::numeric_limits<long>::max()), rng_mt19937);


boost::random::taus88 rng_taus88;
int random_taus88_int()
{
	boost::random::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	return dist(rng_taus88);
}
long random_taus88_long()
{
	boost::random::uniform_int_distribution<long> dist(std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
	return dist(rng_taus88);
}


// WELL512
// http://www.lomont.org/Math/Papers/2008/Lomont_PRNG_2008.pdf
/* initialize state to random bits */
static unsigned long state[16];
/* init should also reset this to 0 */
static unsigned int index = 0;
/* return 32 bit random number */
unsigned long WELLRNG512(void)
{
	unsigned long a, b, c, d;
	a = state[index];
	c = state[(index + 13) & 15];
	b = a^c ^ (a << 16) ^ (c << 15);
	c = state[(index + 9) & 15];
	c ^= (c >> 11);
	a = state[index] = b^c;
	d = a ^ ((a << 5) & 0xDA442D24UL);
	index = (index + 15) & 15;
	a = state[index];
	state[index] = a^b^d ^ (a << 2) ^ (b << 18) ^ (c << 28);
	return state[index];
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



// int
BASELINE(int, rand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(rand());
}


BENCHMARK(int, mt19937, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(random_mt19937_int());
}


BENCHMARK(int, WELL512, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(static_cast<int>(WELLRNG512()));// using long
}


BENCHMARK(int, taus88, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(random_taus88_int());
}


BENCHMARK(int, intel_fastrand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(fastrand());
}


BENCHMARK(int, xorshiftplus, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(static_cast<int>(xorshift128plus()));// using uint64_t
}


// long
BASELINE(long, rand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway( (static_cast<long>(rand()) << (sizeof(int) * 8 - 1)) | rand() );
}


BENCHMARK(long, mt19937, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(random_mt19937_long());
}


BENCHMARK(long, WELL512, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(WELLRNG512());
}


BENCHMARK(long, taus88, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(random_taus88_long());
}


BENCHMARK(long, intel_fastrand, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway((static_cast<long>(fastrand()) << (sizeof(int) * 8 - 1)) | fastrand());
}


BENCHMARK(long, xorshiftplus, g_samples, g_iterations)
{
	for (size_t i = 0; i < g_loop; ++i)
		celero::DoNotOptimizeAway(xorshift128plus());
}