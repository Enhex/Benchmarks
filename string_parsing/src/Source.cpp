#include <boost/spirit/include/karma_generate.hpp>
#include <boost/spirit/include/karma_real.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/qi_auto.hpp>
#include <boost/spirit/include/qi_no_skip.hpp>
#include <boost/spirit/include/qi_numeric.hpp>
#include <boost/spirit/include/qi_parse_auto.hpp>
#include <boost/spirit/include/support_ascii.hpp>
#include <celero/Celero.h>
#include <fmt/format.h>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/core.hpp>
#include <boost/spirit/home/x3/numeric.hpp>
//#include <formatxx/format.h>
//#include <formatxx/string.h>


CELERO_MAIN

// toggle to inspect
//#define INSPECT_OUTPUT

// toggle
//#define DO_NOT_OPTIMIZE


#ifdef INSPECT_OUTPUT
constexpr int g_samples = 1;
constexpr int g_iterations = 1;
#else
constexpr int g_samples = 1000;
constexpr int g_iterations = 1000;
#endif

std::mt19937 rng;
auto distribution_int = std::uniform_int_distribution<>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
auto random_int = [] {
	return distribution_int(rng);
};

//auto distribution_float = std::uniform_real_distribution<float>(std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max());
auto distribution_float = std::uniform_real_distribution<float>(-1000000, 1000000);
auto random_float = [] {
	return distribution_float(rng);
};

template <typename T>
struct fixed_policy : boost::spirit::karma::real_policies<T> {
	typedef boost::spirit::karma::real_policies<T> base_type;
	static int floatfield(T) { return base_type::fmtflags::fixed; }
	static unsigned int precision(T) { return 10; }
};

using float_fixed_type = boost::spirit::karma::real_generator<double, fixed_policy<float>>;
auto const float_fixed = float_fixed_type();


fmt::memory_buffer g_buf;

std::string naive_int_to_str(int x)
{
	constexpr char ascii_offset = 48;

	std::string str;

	if (x < 0) {
		x *= -1;
		str += '-';
	}

	while (x > 0) {
		str += static_cast<unsigned char>(x % 10) + ascii_offset;
		x /= 10;
	}

	std::reverse(str.begin() + (str[0] == '-'), str.end());

	return str;
}



template<unsigned max>
char get_digit(int& x)
{
	const auto d = x / max;
	x -= d * max;
	return d;
}

std::string naive2_int_to_str(int x)
{
	constexpr char ascii_offset = 48;

	std::string str;

	if (x < 0) {
		x *= -1;
		str += '-';
	}

	const auto write_digit = [&str, &ascii_offset](char d) {
		str += d + ascii_offset;
	};

	{
		constexpr unsigned max = 1000000000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 100000000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 10000000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 1000000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 100000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 10000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 1000;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 100;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 10;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}
	{
		constexpr unsigned max = 1;
		if (x >= max)
			write_digit(get_digit<max>(x));
	}

	return str;
}


struct IntFixture : celero::TestFixture
{
	int value;
	std::string value_str;
	
	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		value = random_int();
		value_str = std::to_string(value);
	}
};

struct FloatFixture : celero::TestFixture
{
	float value;
	std::string value_str;

	void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
	{
		value = 12345.6789f;//random_float();
		std::stringstream ss;
		ss << value;
		value_str = ss.str();
	}
};

// int to string
BASELINE_F(int_to_str, to_string, IntFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = std::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
	;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, sstream, IntFixture, g_samples, g_iterations)
{
	std::stringstream ss;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		ss << value
#ifdef DO_NOT_OPTIMIZE
	)
#endif
	;

#ifdef INSPECT_OUTPUT
	std::cout << ss.str() << std::endl;
#endif
}

BENCHMARK_F(int_to_str, karma, IntFixture, g_samples, g_iterations)
{
	std::string s;
	std::back_insert_iterator<std::string> sink(s);

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		boost::spirit::karma::generate(sink, value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
	;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, karma_int_, IntFixture, g_samples, g_iterations)
{
	using namespace boost::spirit::karma;

	std::string s;
	std::back_insert_iterator<std::string> sink(s);

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		generate(sink, int_(value))
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, karma_reserve, IntFixture, g_samples, g_iterations)
{
	std::string s;
	s.reserve(50);

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		boost::spirit::karma::generate(s.begin(), value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, karma_ins_reserve, IntFixture, g_samples, g_iterations)
{
	using boost::spirit::karma::int_inserter;

	std::string s;
	s.reserve(50);
	auto iter = s.begin();

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		int_inserter<10>::call(iter, value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, karma_ins_buff, IntFixture, g_samples, g_iterations)
{
	using boost::spirit::karma::int_inserter;

	char buffer[50];
	char* p = buffer;


#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		int_inserter<10>::call(p, value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << buffer << std::endl;
#endif
}

BENCHMARK_F(int_to_str, fmt_format, IntFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = fmt::format("{}", value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, fmt_to_string, IntFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = fmt::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, fmt_buffer, IntFixture, g_samples, g_iterations)
{
	std::string s;
	fmt::memory_buffer buf;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
	format_to(buf, "{}", value);
	s = buf.data();
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, fmt_buffer_g, IntFixture, g_samples, g_iterations)
{
	std::string s;
	g_buf.clear();

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
	format_to(g_buf, "{}", value);
	s = g_buf.data();
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, naive, IntFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = naive_int_to_str(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(int_to_str, naive2, IntFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = naive2_int_to_str(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}




// float to string
BASELINE_F(float_to_str, to_string, FloatFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = std::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;	// keeps trailing zeros
#endif
}
BENCHMARK_F(float_to_str, to_string_trim, FloatFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = std::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

	// trim zeros and decimal point
	const auto pos = s.find_last_not_of('0');
	if(s[pos] == '.')
		s.erase(pos);
	else
		s.erase(pos+1);

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(float_to_str, to_string_trim2, FloatFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = std::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

	// trim trailing zeros and decimal point
	const auto pos = s.find_last_not_of('0');
	s.erase(pos + (s[pos] != '.'));

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(float_to_str, to_string_trim3, FloatFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = std::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

	// trim zeros and decimal point
	for (size_t pos = s.size() - 1; pos > 0/*not erasing last char*/; --pos) {
		if (s[pos] != '0') {
			s.erase(pos + (s[pos] != '.'));
			break;
		}
	}

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}

BENCHMARK_F(float_to_str, sstream, FloatFixture, g_samples, g_iterations)
{
	std::stringstream ss;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		ss << value
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << ss.str() << std::endl;	// no redundant trail
#endif
}

BENCHMARK_F(float_to_str, karma, FloatFixture, g_samples, g_iterations)
{
	std::string s;
	std::back_insert_iterator<std::string> sink(s);

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		boost::spirit::karma::generate(sink, value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;	// if no fraction, keeps trailing ".0"
#endif
}

BENCHMARK_F(float_to_str, karma_fixed, FloatFixture, g_samples, g_iterations)
{
	std::string s;
	std::back_insert_iterator<std::string> sink(s);

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		boost::spirit::karma::generate(sink, float_fixed, value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;	// if no fraction, keeps trailing ".0"
#endif
}

BENCHMARK_F(float_to_str, fmt_format, FloatFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = fmt::format("{}", value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;	// no redundant trail
#endif
}

BENCHMARK_F(float_to_str, fmt_to_string, FloatFixture, g_samples, g_iterations)
{
	std::string s;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		s = fmt::to_string(value)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;	// no redundant trail
#endif
}

BENCHMARK_F(float_to_str, fmt_buffer, FloatFixture, g_samples, g_iterations)
{
	std::string s;
	fmt::memory_buffer buf;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
	format_to(buf, "{}", value);
	s = buf.data();
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;	// no redundant trail
#endif
}

BENCHMARK_F(float_to_str, fmt_buffer_g, FloatFixture, g_samples, g_iterations)
{
	std::string s;
	g_buf.clear();

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
	format_to(g_buf, "{}", value);
	s = g_buf.data();
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;

#ifdef INSPECT_OUTPUT
	std::cout << s << std::endl;
#endif
}


// string to int
BASELINE_F(str_to_int, stoi, IntFixture, g_samples, g_iterations)
{
	int i;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		i = std::stoi(value_str)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;
}

BENCHMARK_F(str_to_int, qi, IntFixture, g_samples, g_iterations)
{
	namespace qi = boost::spirit::qi;

	int i;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		qi::phrase_parse(value_str.begin(), value_str.end(), qi::auto_, boost::spirit::ascii::space, i)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;
}

BENCHMARK_F(str_to_int, x3, IntFixture, g_samples, g_iterations)
{
	namespace x3 = boost::spirit::x3;

	int i;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		x3::phrase_parse(value_str.begin(), value_str.end(), x3::int_parser<int>(), x3::ascii::space, i)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;
}


// string to float
BASELINE_F(str_to_float, stof, FloatFixture, g_samples, g_iterations)
{
	float x;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		x = std::stof(value_str)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;
}

BENCHMARK_F(str_to_float, qi, FloatFixture, g_samples, g_iterations)
{
	namespace qi = boost::spirit::qi;

	float x;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		qi::phrase_parse(value_str.begin(), value_str.end(), qi::auto_, boost::spirit::ascii::space, x)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;
}

BENCHMARK_F(str_to_float, x3, FloatFixture, g_samples, g_iterations)
{
	namespace x3 = boost::spirit::x3;

	float x;

#ifdef DO_NOT_OPTIMIZE
	celero::DoNotOptimizeAway(
#endif
		x3::phrase_parse(value_str.begin(), value_str.end(), x3::real_parser<float>(), x3::ascii::space, x)
#ifdef DO_NOT_OPTIMIZE
	)
#endif
		;
}