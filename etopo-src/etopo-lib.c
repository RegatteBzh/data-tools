#include "etopo-lib.h"
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>


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

void deleteBlock(int16_t* map) {
    free(map);
}

int sign(float f) {
    return f > 0 ? 1 : -1;
}

void getCoord(char* str, int* deg, int* minutes) {
    float f = (float)atof(str);
    *deg = (int)f;
    *minutes = abs((int)((f - (float)*deg) * 100)) * sign(*deg);
}

int modulo(int angle, int mod) {
    while (angle<0) {
        angle += mod;
    }
    return angle% mod;
}

int getAltitude(int16_t* map, int lon, int lat) {
    //recenter
    lat = modulo(lat + toMinutes(90, 0), toMinutes(180, 0));
    lon = modulo(lat + toMinutes(180, 0), toMinutes(360, 0));
    // get value
    return map[lat * NCOLS + lon];
}

int toMinutes(int deg, int min) {
    return deg * 60 + min;
}