/**
 * Tool to read ETOPO data
 *
 * Cyrille Meichel <cmeichel@free.fr> 2016/11
 *
 **/

#include <stdio.h>
#include <stdint.h>
#include "etopo-lib.h"

int16_t* map;


int main (int argc, char** argv) {
    FILE* fp;
    char* filename;
    int latD = 0;
    int latM = 0;
    int lonD = 0;
    int lonM = 0;
    int lon=0;
    int lat=0;

    printf("%s <filename_i2.bin> [lon lat]\n", argv[0]);
    printf("\te.i. %s ../relief/etopo1_ice_g_i2.bin -100.05 12.20\n", argv[0]);


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

        // Convert longitude and latitude in minutes
        lon = toMinutes(lonD, lonM);
        lat = toMinutes(latD, latM);
        
        printf("Lon: %d°%d' (%d')\nLat: %d°%d' (%d')\n", lonD, lonM, lon, latD, latM, lat);
        printf("Height: %d m\n", getAltitude(map, lon, lat));
    }

    deleteBlock(map);

    // End
    return 0;
}