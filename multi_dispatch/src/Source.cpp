#include <celero/Celero.h>
#include <random>
#include <array>

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

// using visitor pattern (2 vtables)
namespace visitor_pattern
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

// using dynamic cast
namespace cast
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
		virtual int f(B& b) = 0;
		virtual int f(C& b) = 0;
	};

	struct A1 : A
	{
		int x = 1;

		int f(B& b) override;
		int f(C& c) override;
	};

	struct A2 : A
	{
		int x = 2;

		int f(B& b) override;
		int f(C& c) override;
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


	int A1::f(B& b)
	{
		if (auto* b1 = dynamic_cast<B1*>(&b)) {
			return b1->f(*this);
		}
		else if (auto* b2 = dynamic_cast<B2*>(&b)) {
			return b2->f(*this);
		}
	}
	int A1::f(C& c)
	{
		if (auto* c1 = dynamic_cast<C1*>(&c)) {
			return c1->f(*this);
		}
		else if (auto* c2 = dynamic_cast<C2*>(&c)) {
			return c2->f(*this);
		}
	}


	int A2::f(B& b)
	{
		if (auto* b1 = dynamic_cast<B1*>(&b)) {
			return b1->f(*this);
		}
		else if (auto* b2 = dynamic_cast<B2*>(&b)) {
			return b2->f(*this);
		}
	}
	int A2::f(C& c)
	{
		if (auto* c1 = dynamic_cast<C1*>(&c)) {
			return c1->f(*this);
		}
		else if (auto* c2 = dynamic_cast<C2*>(&c)) {
			return c2->f(*this);
		}
	}
}

// virtual function, then type ID to function lookup table (id defined as a member variable in derived class)
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

		template<typename T = A1>
		constexpr int f_AN(A& a) {
			auto& an = static_cast<T&>(a);
			return 1 + an.x;
		}
		constexpr int f_A2(A& a) {
			auto& an = static_cast<A2&>(a);
			return 2 + an.x;
		}

		static constexpr int(this_t::* f_A [2])(A& a) = {
			&this_t::f_AN,
			&this_t::f_A2
		};

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

		static constexpr int(this_t::* f_A [2])(A& a) = {
			&this_t::f_A1,
			&this_t::f_A2
		};

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

		static constexpr int(this_t::* f_A [2])(A& a) = {
			&this_t::f_A1,
			&this_t::f_A2
		};

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

		static constexpr int(this_t::* f_A [2])(A& a) = {
			&this_t::f_A1,
			&this_t::f_A2
		};

		int f(A& a) override {
			return (this->*f_A[a.id])(a);
		}
	};
}

// virtual function, then type ID to function lookup table (id defined as a return value of a virtual function)
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

// use type ID to function lookup table twice (id defined as a member variable in derived class)
namespace id_double_map
{
	struct B
	{
		enum type : uint_fast8_t {
			B1,
			B2,
			count
		};

		type const id;
	};

	struct C
	{
		enum type : uint_fast8_t {
			C1,
			C2,
			count
		};

		type const id;
	};

	struct A
	{
		enum type : uint_fast8_t {
			A1,
			A2,
			count
		};

		type const id; // id per object instance. the extra memory is comparable to needing a pointer to a vtable

					   // for testing if the overhead of the id var + vtable is worse than virtual id()
#ifdef ID_VAR_AND_VIRTUAL
		A(A_type id) noexcept : id(id) {}
		virtual void test(){};
#endif
	};

	struct A1 : A
	{
		static constexpr auto id = type::A1;
		A1() : A{id} {}
		int x = 1;
	};

	struct A2 : A
	{
		static constexpr auto id = type::A2;
		A2() : A{id} {}
		int x = 2;
	};


	struct B1 : B
	{
		static constexpr auto id = type::B1;
		B1() : B{id} {}
	};

	struct B2 : B
	{
		static constexpr auto id = type::B2;
		B2() : B{id} {}
	};

	int f_B1_A1(B& b, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 1 + an.x;
	}
	int f_B1_A2(B& b, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 2 + an.x;
	}
	int f_B2_A1(B& b, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 3 + an.x;
	}
	int f_B2_A2(B& b, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 4 + an.x;
	}

	constexpr auto f_B = []{
		std::array<std::array<int(*)(B& b, A& a), A::count>, B::count> map = {nullptr};
		// this way if the ID of a type changes, it won't require manually reordering the map so the right function will be at the right array index
		map[B1::id][A1::id] = &f_B1_A1;
		map[B1::id][A2::id] = &f_B1_A2;
		map[B2::id][A1::id] = &f_B2_A1;
		map[B2::id][A2::id] = &f_B2_A2;

		return map;
	}();

	int f(B& b, A& a) {
		return f_B[b.id][a.id](b, a);
	}

	struct C1 : C
	{
		C1() : C{type::C1} {}
	};

	struct C2 : C
	{
		C2() : C{type::C2} {}
	};

	int f_C1_A1(C& c, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 1 + an.x;
	}
	int f_C1_A2(C& c, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 2 + an.x;
	}
	int f_C2_A1(C& c, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 3 + an.x;
	}
	int f_C2_A2(C& c, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 4 + an.x;
	}

	constexpr int(* f_C [2][2])(C& c, A& a) = {
		{
			&f_C1_A1,
			&f_C1_A2,
		},
		{
			&f_C2_A1,
			&f_C2_A2
		}
	};

	int f(C& c, A& a) {
		return f_C[c.id][a.id](c, a);
	}
}

// single array map which is accessed by combining the type IDs into a single index
namespace id_single_map
{
	struct B
	{
		enum type : uint_fast8_t {
			B1,
			B2,
			count
		};

		type const id;
	};

	struct C
	{
		enum type : uint_fast8_t {
			C1,
			C2,
			count
		};

		type const id;
	};

	struct A
	{
		enum type : uint_fast8_t {
			A1,
			A2,
			count
		};

		type const id; // id per object instance. the extra memory is comparable to needing a pointer to a vtable

		// for testing if the overhead of the id var + vtable is worse than virtual id()
#ifdef ID_VAR_AND_VIRTUAL
		A(A_type id) noexcept : id(id) {}
		virtual void test(){};
#endif
	};

	struct A1 : A
	{
		static constexpr auto id = type::A1;
		A1() : A{id} {}
		int x = 1;
	};

	struct A2 : A
	{
		static constexpr auto id = type::A2;
		A2() : A{id} {}
		int x = 2;
	};


	struct B1 : B
	{
		static constexpr auto id = type::B1;
		B1() : B{id} {}
	};

	struct B2 : B
	{
		static constexpr auto id = type::B2;
		B2() : B{id} {}
	};

	int f_B1_A1(B& b, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 1 + an.x;
	}
	int f_B1_A2(B& b, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 2 + an.x;
	}
	int f_B2_A1(B& b, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 3 + an.x;
	}
	int f_B2_A2(B& b, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 4 + an.x;
	}

	template<typename Column, typename Row>
	constexpr auto index()
	{
		constexpr auto row_size = Row::count;
		return Column::id * row_size + Row::id;
	};

	constexpr auto f_B = []{
		std::array<int(*)(B& b, A& a), B::count * A::count> map = {nullptr};
		// this way if the ID of a type changes, it won't require manually reordering the map so the right function will be at the right array index
		map[index<B1, A1>()] = &f_B1_A1;
		map[index<B1, A2>()] = &f_B1_A2;
		map[index<B2, A1>()] = &f_B2_A1;
		map[index<B2, A2>()] = &f_B2_A2;

		return map;
	}();

	int f(B& b, A& a) {
		return f_B[b.id * A::count + a.id](b, a);
	}

	struct C1 : C
	{
		C1() : C{type::C1} {}
	};

	struct C2 : C
	{
		C2() : C{type::C2} {}
	};

	int f_C1_A1(C& c, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 1 + an.x;
	}
	int f_C1_A2(C& c, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 2 + an.x;
	}
	int f_C2_A1(C& c, A& a)
	{
		auto& an = static_cast<A1&>(a);
		return 3 + an.x;
	}
	int f_C2_A2(C& c, A& a)
	{
		auto& an = static_cast<A2&>(a);
		return 4 + an.x;
	}

	constexpr int(* f_C [4])(C& c, A& a) = {&f_C1_A1, &f_C1_A2, &f_C2_A1, &f_C2_A2};

	int f(C& c, A& a) {
		return f_C[c.id * A::count + a.id](c, a);
	}
}

struct VP_Fixture : celero::TestFixture
{
	visitor_pattern::A1 a1;
	visitor_pattern::A2 a2;

	visitor_pattern::B1 b1;
	visitor_pattern::B2 b2;

	visitor_pattern::C1 c1;
	visitor_pattern::C2 c2;

	visitor_pattern::A* a;
	visitor_pattern::B* b;
	visitor_pattern::C* c;
};

struct DC_Fixture : celero::TestFixture
{
	cast::A1 a1;
	cast::A2 a2;

	cast::B1 b1;
	cast::B2 b2;

	cast::C1 c1;
	cast::C2 c2;

	cast::A* a;
	cast::B* b;
	cast::C* c;
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

struct IDM_Fixture : celero::TestFixture
{
	id_double_map::A1 a1;
	id_double_map::A2 a2;

	id_double_map::B1 b1;
	id_double_map::B2 b2;

	id_double_map::C1 c1;
	id_double_map::C2 c2;

	id_double_map::A* a;
	id_double_map::B* b;
	id_double_map::C* c;
};

struct ISM_Fixture : celero::TestFixture
{
	id_single_map::A1 a1;
	id_single_map::A2 a2;

	id_single_map::B1 b1;
	id_single_map::B2 b2;

	id_single_map::C1 c1;
	id_single_map::C2 c2;

	id_single_map::A* a;
	id_single_map::B* b;
	id_single_map::C* c;
};


BASELINE_F(multi_dispatch, visitor_pattern, VP_Fixture, g_samples, g_iterations)
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


BENCHMARK_F(multi_dispatch, dynamic_cast, DC_Fixture, g_samples, g_iterations)
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

	auto res1 = a->f(*b);
	auto res2 = a->f(*c);
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


BENCHMARK_F(multi_dispatch, id_double_map, IDM_Fixture, g_samples, g_iterations)
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

	auto res1 = f(*b, *a);
	auto res2 = f(*c, *a);
	celero::DoNotOptimizeAway(res1);
	celero::DoNotOptimizeAway(res2);
}


BENCHMARK_F(multi_dispatch, id_single_map, ISM_Fixture, g_samples, g_iterations)
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

	auto res1 = f(*b, *a);
	auto res2 = f(*c, *a);
	celero::DoNotOptimizeAway(res1);
	celero::DoNotOptimizeAway(res2);
}