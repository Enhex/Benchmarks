#include <celero/Celero.h>

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/stream.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <mmaplib.h>

CELERO_MAIN

constexpr int g_samples = 30;
constexpr int g_iterations = 200;

namespace io = boost::iostreams;

BASELINE(group, fstream, g_samples, g_iterations)
{
	std::ifstream is("test.txt", std::ifstream::binary);

	// get length of file:
	is.seekg(0, is.end);
	int length = is.tellg();
	is.seekg(0, is.beg);

	char * buffer = new char[length+1];
	buffer[length] = 0;

	// read data as a block:
	is.read(buffer, length);
	//std::cout << buffer;

	// ...buffer contains the entire file...
	is.close();
	delete[] buffer;
}


BENCHMARK(group, fread, g_samples, g_iterations)
{
	FILE * pFile = fopen("./test.txt", "rb");
	assert(pFile != NULL);

	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	long length = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	auto buffer = new char[length + 1];
	buffer[length] = 0;

	// copy the file into the buffer:
	auto result = fread(buffer, 1, length, pFile);
	//std::cout << buffer;

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose(pFile);
	free(buffer);
}


BENCHMARK(group, fstream_buffer, g_samples, g_iterations)
{
	std::ifstream is("test.txt", std::ifstream::binary);

	// get length of file:
	is.seekg(0, is.end);
	int length = is.tellg();
	is.seekg(0, is.beg);

	auto buffer = new char[length + 1];
	buffer[length] = 0;

	is.rdbuf()->pubsetbuf(buffer, length);

	// read data as a block:
	is.read(buffer, length);
	//std::cout << buffer;

	// ...buffer contains the entire file...
	is.close();
	delete[] buffer;
}

// doesn't work anymore
// BENCHMARK(group, boost_mapped_file, g_samples, g_iterations)
// {
// 	boost::iostreams::mapped_file_source file("./test.txt");

// 	//std::cout << file.data();

// 	file.close();
// }


BENCHMARK(group, mmaplib, g_samples, g_iterations)
{
	mmaplib::MemoryMappedFile file("./test.txt");

	//std::cout << file.data();
}

// wrong usage?
//BENCHMARK(group, boost_file, g_samples, g_iterations)
//{
//	io::stream<io::file_source> is("test.txt");
//
//	is.seekg(0, is.end);
//	int length = is.tellg();
//	is.seekg(0, is.beg);
//
//	char * buffer = new char[length];
//	is.read(buffer, length);
//
//	//std::cout << buffer;
//
//	is.close();
//}


//BENCHMARK(group, boost_filemapping, g_samples, g_iterations)
//{
//	using namespace boost::interprocess;
//	file_mapping m_file("test.txt", read_only);
//
//	// get length of file:
//	std::ifstream is("test.txt", std::ifstream::binary);
//	is.seekg(0, is.end);
//	int length = is.tellg();
//	is.seekg(0, is.beg);
//
//	mapped_region region(m_file, read_write, 0, length);
//	region.flush();
//}