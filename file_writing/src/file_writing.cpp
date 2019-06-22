#include <celero/Celero.h>
#include <fstream>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cpuinfo.h>

size_t l1_size = 0;

int main(int argc, char** argv)
{
	cpuinfo_initialize();
	l1_size = cpuinfo_get_processor(0)->cache.l1d->size;

	celero::Run(argc, argv);
	return 0;
}

constexpr int g_samples = 10;
constexpr int g_iterations = 100;


constexpr size_t content_size = 1000000;
char content[content_size];


namespace io = boost::iostreams;

BASELINE(group, fstream, g_samples, g_iterations)
{
	std::ofstream s("test.txt", std::ifstream::binary);

	s.write(content, content_size);

	s.close();
}

BENCHMARK(group, fstream_buffered, g_samples, g_iterations)
{
	std::ofstream s("test.txt", std::ifstream::binary);

	constexpr size_t length = 1 << 14;
	char * buffer = new char[length];
	s.rdbuf()->pubsetbuf(buffer, length);

	s.write(content, content_size);

	s.close();
	delete[] buffer;
}

BENCHMARK(group, fstream_buf_cache, g_samples, g_iterations)
{
	std::ofstream s("test.txt", std::ifstream::binary);

	const auto length = l1_size;

	auto buffer = new char[length];
	s.rdbuf()->pubsetbuf(buffer, length);

	s.write(content, content_size);

	s.close();
	delete[] buffer;
}


BENCHMARK(group, fwrite, g_samples, g_iterations)
{
	FILE * file = fopen("test.txt", "wb");

	size_t result = fwrite(content, sizeof(char), content_size, file);

	fclose(file);
}


BENCHMARK(group, boost_file, g_samples, g_iterations)
{
	io::file_sink file("test.txt");

	file.write(content, content_size);

	//std::cout << buffer;

	file.close();
}