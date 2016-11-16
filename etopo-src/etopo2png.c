/**
 * Tool to create a png from ETOPO
 *
 * Cyrille Meichel <cmeichel@free.fr> 2016/11
 *
 **/

#include <stdio.h>
#include <stdint.h>
#include "etopo-lib.h"
#include <png.h>
#include <malloc.h>

int16_t* map;


int main (int argc, char** argv) {
    FILE* fp;
    FILE* fpIn;
    char* filename;
    char* png;
    int latD = 0;
    int latM = 0;
    int lonD = 0;
    int lonM = 0;
    int lon=0;
    int lat=0;
    png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;
    int width = NCOLS;
    int height = NROWS;
    char* title = "ETOPO1";
    int maxLevel = 0;
    int minLevel = 0;
    int i;

    printf("%s <filename_i2.bin> <filename.png>\n", argv[0]);
    printf("\te.i. %s ../relief/etopo1_ice_g_i2.bin etopo.png\n", argv[0]);


    // Check arguments
    if (argc < 3) {
        fprintf(stderr, "Not enough arguments\n%s <filename_i2.bin>\n", argv[0]);
        return 1;
    }
    filename = argv[1];
    png = argv[2];

    // Open the file
    fpIn = fopen(filename,"rb");
    if (!fpIn) {
        fprintf(stderr, "Could not open %s\n", filename);
        return 1;
    }

    fp = fopen(png, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return 1;
    }

    // Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "Could not allocate write struct\n");
		return 1;
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "Could not allocate info struct\n");
		return 1;
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr))) {
		fprintf(stderr, "Error during png creation\n");
		return 1;
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
			8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Set title
	if (title != NULL) {
		png_text title_text;
		title_text.compression = PNG_TEXT_COMPRESSION_NONE;
		title_text.key = "etopo1";
		title_text.text = title;
		png_set_text(png_ptr, info_ptr, &title_text, 1);
	}

	png_write_info(png_ptr, info_ptr);

    // Allocate memory for one row (3 bytes per pixel - RGB)
    row = (png_bytep) malloc(3 * width * sizeof(png_byte));

    // read etopo
    map = readBlock(fpIn);
    for(i=0; i< NCOLS * NROWS; i++) {
        maxLevel = map[i] > maxLevel ? map[i] : maxLevel;
        minLevel = map[i] < minLevel ? map[i] : minLevel;
    }
    printf("Max: %d\nMin: %d\n", maxLevel, minLevel);

    // Write image data
	int x, y;
	for (y=0 ; y<height ; y++) {
		for (x=0 ; x<width ; x++) {
            unsigned char rgb[3] = {0,0,0};
            if (map[y * NCOLS + x] < 0) {
                double h = (double)(map[y * NCOLS + x] - minLevel) / (double)(-minLevel);
                //hslToRgb(240/360, 1, h / h, rgb);
                rgb[0] = 0;
                rgb[1] = 0;
                rgb[2] = h * (double)255;
            } else {
                double h = (double)(map[y * NCOLS + x] - maxLevel) / (double)(maxLevel);
                //hslToRgb(120/360, 1, h, rgb);
                rgb[0] = 0;
                rgb[1] = h * (double)255;
                rgb[2] = 0;
            }
            row[3*x] = rgb[0];
            row[3*x + sizeof(png_byte)] = rgb[1];
            row[3*x + 2 * sizeof(png_byte)] = rgb[2];
            //printf("%d ", )
		}
		png_write_row(png_ptr, row);
	}

	// End write
	png_write_end(png_ptr, NULL);

	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
	free(row);

    deleteBlock(map);
    fclose(fp);
    fclose(fpIn);

    // End
    return 0;
}