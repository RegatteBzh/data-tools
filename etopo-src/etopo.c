/**
 * Tool to convert wind forecast (1deg) bin file to json
 *
 * Cyrille Meichel <cmeichel@free.fr> 2016/11
 *
 **/

#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>

#define NCOLS         21601
#define NROWS         10801

/**
 * @param count Number of samples
 * @param fp    File
 * @returns Buffer (array of floats)
 */
int16_t* readBlock(FILE* fp) {

    int16_t* buffer = (int16_t*)malloc(sizeof(int16_t) * NCOLS * NROWS);

    // Read complete buffer
    fread(buffer, sizeof(int16_t), NCOLS * NROWS, fp);

    return buffer;
}

void getCoord(char* str, int* deg, int* minutes) {
    float f = (float)atof(str);
    *deg = (int)f;
    *minutes = abs((int)((f - (float)*deg) * 100));
}

int main (int argc, char** argv) {
    FILE* fp;
    char* filename;
    int16_t* map;
    int latD = 0;
    int latM = 0;
    int lonD = 0;
    int lonM = 0;
    int lon=0;
    int lat=0;

    printf("%s <filename_i2.bin> [lon lat]\n", argv[0]);


    // Check arguments
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n%s <filename_i2.bin>\n", argv[0]);
        return 1;
    }
    filename = argv[1];

    // Open the file
    fp = fopen(filename,"rb");
    if (!fp) {
        fprintf(stderr, "Could not open %s\n", filename);
        return 1;
    }

    map = readBlock(fp);

    if (argc>3) {
        getCoord(argv[2], &lonD, &lonM);
        getCoord(argv[3], &latD, &latM);
        lon = (lonD % 180) * 60 + lonM * lonD/abs(lonD) + 180 * 60;
        lat = (latD % 90) * 60 + latM * latD/abs(latD) + 90 * 60;
        printf("Lon: %d°%d (%d)\nLat: %d°%d (%d)\n", lonD, lonM, lon, latD, latM, lat);
    }

    free(map);

    // End
    return 0;
}