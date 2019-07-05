#include <celero/Celero.h>
#include <random>

// intel fastrand
// https://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor
static unsigned int g_fastrand_seed = std::random_device()();
inline int fastrand() {
	g_fastrand_seed = (214013 * g_fastrand_seed + 2531011);
	return (g_fastrand_seed >> 16) & 0x7FFF;
}

CELERO_MAIN

constexpr int g_samples = 100;
constexpr int g_iterations = 500000;

//#define ID_VAR_AND_VIRTUAL

namespace double_dispatch
{
	struct A1;
	struct A2;

	struct B
	{
		virtual int f(A1& a) = 0;
		virtual int f(A2& a) = 0;
	};

	struct C
	{
		virtual int f(A1& a) = 0;
		virtual int f(A2& a) = 0;
	};

	struct A
	{
		virtual int accept_f(B& b) = 0;
		virtual int accept_f(C& b) = 0;
	};

	struct A1 : A
	{
		int x = 1;
		int accept_f(B& b) override {
			return b.f(*this);
		}
		int accept_f(C& c) override {
			return c.f(*this);
		}
	};

	struct A2 : A
	{
		int x = 2;
		int accept_f(B& b) override {
			return b.f(*this);
		}
		int accept_f(C& c) override {
			return c.f(*this);
		}
	};


	struct B1 : B
	{
		int f(A1& a) override {
			return 1 + a.x;
		}
		int f(A2& a) override {
			return 2 + a.x;
		}
	};

	struct B2 : B
	{
		int f(A1& a) override {
			return 3 + a.x;
		}
		int f(A2& a) override {
			return 4 + a.x;
		}
	};

	struct C1 : C
	{
		int f(A1& a) override {
			return 5 + a.x;
		}
		int f(A2& a) override {
			return 6 + a.x;
		}
	};

	struct C2 : C
	{
		int f(A1& a) override {
			return 7 + a.x;
		}
		int f(A2& a) override {
			return 8 + a.x;
		}
	};
}

namespace id_map
{
	struct A;

	struct B
	{
		virtual int f(A& a) = 0;
	};

	struct C
	{
		virtual int f(A& a) = 0;
	};

	struct A
	{
		enum A_type : uint_fast8_t {
			A1,
			A2
		};

		A_type const id; // id per object instance. the extra memory is comparable to needing a pointer to a vtable

		// for testing if the overhead of the id var + vtable is worse than virtual id()
#ifdef ID_VAR_AND_VIRTUAL
		A(A_type id) noexcept : id(id) {}
		virtual void test(){};
#endif
	};

	struct A1 : A
	{
		int x = 1;
		A1() : A{A_type::A1}
		{
		}
	};

	struct A2 : A
	{
		int x = 2;
		A2() : A{A_type::A2}
		{
		}
	};


	struct B1 : B
	{
		using this_t = B1;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 1 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 2 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id])(a);
		}
	};

	struct B2 : B
	{
		using this_t = B2;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 3 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 4 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id])(a);
		}
	};

	struct C1 : C
	{
		using this_t = C1;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 5 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 6 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id])(a);
		}
	};

	struct C2 : C
	{
		using this_t = C2;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 7 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 8 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id])(a);
		}
	};
}

namespace id_map_v
{
	struct A;

	struct B
	{
		virtual int f(A& a) = 0;
	};

	struct C
	{
		virtual int f(A& a) = 0;
	};

	struct A
	{
		enum A_type : uint_fast8_t {
			A1,
			A2
		};

		virtual A_type id() const noexcept = 0;
	};

	struct A1 : A
	{
		int x = 1;
		A_type id() const noexcept override {
			return A_type::A1;
		}
	};

	struct A2 : A
	{
		int x = 2;
		A_type id() const noexcept override {
			return A_type::A2;
		}
	};


	struct B1 : B
	{
		using this_t = B1;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 1 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 2 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id()])(a);
		}
	};

	struct B2 : B
	{
		using this_t = B2;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 3 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 4 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id()])(a);
		}
	};

	struct C1 : C
	{
		using this_t = C1;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 5 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 6 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id()])(a);
		}
	};

	struct C2 : C
	{
		using this_t = C2;

		constexpr int f_A1(A& a) {
			auto& an = static_cast<A1&>(a);
			return 7 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 8 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {&this_t::f_A1, &this_t::f_A2};

		int f(A& a) override {
			return (this->*f_A[a.id()])(a);
		}
	};
}

struct DD_Fixture : celero::TestFixture
{
	double_dispatch::A1 a1;
	double_dispatch::A2 a2;

	double_dispatch::B1 b1;
	double_dispatch::B2 b2;

	double_dispatch::C1 c1;
	double_dispatch::C2 c2;

	double_dispatch::A* a;
	double_dispatch::B* b;
	double_dispatch::C* c;
};

struct IM_Fixture : celero::TestFixture
{
	id_map::A1 a1;
	id_map::A2 a2;

	id_map::B1 b1;
	id_map::B2 b2;

	id_map::C1 c1;
	id_map::C2 c2;

	id_map::A* a;
	id_map::B* b;
	id_map::C* c;
};

struct IMV_Fixture : celero::TestFixture
{
	id_map_v::A1 a1;
	id_map_v::A2 a2;

	id_map_v::B1 b1;
	id_map_v::B2 b2;

	id_map_v::C1 c1;
	id_map_v::C2 c2;

	id_map_v::A* a;
	id_map_v::B* b;
	id_map_v::C* c;
};


BASELINE_F(multi_dispatch, double_dispatch, DD_Fixture, g_samples, g_iterations)
{
	if (fastrand() % 2)
		a = &a1;
	else
		a = &a2;

	if (fastrand() % 2)
		b = &b1;
	else
		b = &b2;

	if (fastrand() % 2)
		c = &c1;
	else
		c = &c2;

	auto res1 = a->accept_f(*b);
	auto res2 = a->accept_f(*c);
	celero::DoNotOptimizeAway(res1);
	celero::DoNotOptimizeAway(res2);
}


BENCHMARK_F(multi_dispatch, id_map, IM_Fixture, g_samples, g_iterations)
{
	if (fastrand() % 2)
		a = &a1;
	else
		a = &a2;

	if (fastrand() % 2)
		b = &b1;
	else
		b = &b2;

	if (fastrand() % 2)
		c = &c1;
	else
		c = &c2;

	auto res1 = b->f(*a);
	auto res2 = c->f(*a);
	celero::DoNotOptimizeAway(res1);
	celero::DoNotOptimizeAway(res2);
}


BENCHMARK_F(multi_dispatch, id_map_virtual, IMV_Fixture, g_samples, g_iterations)
{
	if (fastrand() % 2)
		a = &a1;
	else
		a = &a2;

	if (fastrand() % 2)
		b = &b1;
	else
		b = &b2;

	if (fastrand() % 2)
		c = &c1;
	else
		c = &c2;

	auto res1 = b->f(*a);
	auto res2 = c->f(*a);
	celero::DoNotOptimizeAway(res1);
	celero::DoNotOptimizeAway(res2);
}