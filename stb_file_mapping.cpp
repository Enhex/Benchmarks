#include <celero/Celero.h>
#include <boost/iostreams/device/mapped_file.hpp>

#define STB_IMAGE_IMPLEMENTATION
//#include <stb_boost\stb_image.h>
#include <stb\stb_image.h>

CELERO_MAIN

constexpr int g_samples = 5;
constexpr int g_iterations = 20;


BASELINE(tga, stbi_load, g_samples, g_iterations)
{
	int x, y, n;
	unsigned char* data = stbi_load("test.tga", &x, &y, &n, 0);
}


BENCHMARK(tga, fread, g_samples, g_iterations)
{
	FILE * pFile;
	long lSize;
	unsigned char * buffer;
	size_t result;

	pFile = fopen("test.tga", "rb");

	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	buffer = (unsigned char*)malloc(sizeof(unsigned char)*lSize);

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);

	int x, y, n;
	unsigned char* data = stbi_load_from_memory(buffer, lSize, &x, &y, &n, 0);

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose(pFile);
	free(buffer);
}


BENCHMARK(tga, file_mapping, g_samples, g_iterations)
{
	boost::iostreams::mapped_file_source file;

	file.open("test.tga");

	int x, y, n;
	unsigned char* data = stbi_load_from_memory(reinterpret_cast<const unsigned char*>(file.data()), file.size(), &x, &y, &n, 0);

	file.close();
}





BASELINE(png, stbi_load, g_samples, g_iterations)
{
	int x, y, n;
	unsigned char* data = stbi_load("test.png", &x, &y, &n, 0);
}


BENCHMARK(png, fread, g_samples, g_iterations)
{
	FILE * pFile;
	long lSize;
	unsigned char * buffer;
	size_t result;

	pFile = fopen("test.png", "rb");

	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	// allocate memory to contain the whole file:
	buffer = (unsigned char*)malloc(sizeof(unsigned char)*lSize);

	// copy the file into the buffer:
	result = fread(buffer, 1, lSize, pFile);

	int x, y, n;
	unsigned char* data = stbi_load_from_memory(buffer, lSize, &x, &y, &n, 0);

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose(pFile);
	free(buffer);
}


BENCHMARK(png, file_mapping, g_samples, g_iterations)
{
	boost::iostreams::mapped_file_source file;

	file.open("test.png");

	int x, y, n;
	unsigned char* data = stbi_load_from_memory(reinterpret_cast<const unsigned char*>(file.data()), file.size(), &x, &y, &n, 0);

	file.close();
}