#include <celero/Celero.h>

//#include <image/image.hpp>
//#include <fileio.hpp>
//#include <flif-dec.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

CELERO_MAIN

constexpr int g_samples = 2;
constexpr int g_iterations = 10;


BASELINE(load, png, g_samples, g_iterations)
{
	int x, y, n;
	unsigned char *data = stbi_load("test.png", &x, &y, &n, 0);
	stbi_image_free(data);
}

//NOTE: FLIF is GPL license
// BENCHMARK(load, flif, g_samples, g_iterations)
// {
// 	FILE *file = fopen("test.flif", "rb");
// 	if (!file) return;
// 	FileIO fio(file, "test.flif");
// 	metadata_options md;
// 	md.icc = FLIF_DEFAULT_OPTIONS.color_profile;
// 	md.xmp = FLIF_DEFAULT_OPTIONS.metadata;
// 	md.exif = FLIF_DEFAULT_OPTIONS.metadata;
// 	Images images;
// 	flif_options options = FLIF_DEFAULT_OPTIONS;
// 	flif_decode(fio, images, options, md);
// }