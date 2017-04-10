#include <celero/Celero.h>
#include <fstream>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/device/file.hpp>
#include <iostream>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <libcpuid.h>


cpu_id_t data;

CELERO_MAIN

constexpr int g_samples = 5;
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

	if (cpu_identify(nullptr, &data) < 0) {
		printf("Sorrry, CPU identification failed.\n");
		printf("Error: %s\n", cpuid_error());
	}

	const auto length = data.l1_data_cache * 1024;

	char * buffer = new char[length];
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