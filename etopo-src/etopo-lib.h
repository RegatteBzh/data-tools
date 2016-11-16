#ifndef __ETOPO_LIB_H__
#define __ETOPO_LIB_H__

#define NCOLS         21601
#define NROWS         10801

#include <stdint.h>
#include <stdio.h>

int16_t* readBlock(FILE* fp);
void deleteBlock(int16_t* map);
int sign(float f);
void getCoord(char* str, int* deg, int* minutes);
int modulo(int angle, int mod);
int getAltitude(int16_t* map, int lon, int lat);
int toMinutes(int deg, int min);

#endif