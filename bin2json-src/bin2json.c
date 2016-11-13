/**
 * Tool to convert wind forecast (1deg) bin file to json
 *
 * Cyrille Meichel <cmeichel@free.fr> 2016/11
 *
 **/

#include <stdio.h>
#include <malloc.h>

#define DATA_COUNT 181*360

int main (int argc, char** argv) {
    FILE* fp;
    char* filename;
    float* UGRD;
    float* VGRD;
    int i;
    int longitude;
    int latitude;

    // Check arguments
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n%s <filename.bin>\n", argv[0]);
        return 1;
    }
    filename = argv[1];

    // Open the file
    fp = fopen(filename,"rb");
    if (!fp) {
        fprintf(stderr, "Could not open %s\n", filename);
        return 1;
    }

    //Memory allocation
    UGRD = (float*) malloc(DATA_COUNT * sizeof(float));
    VGRD = (float*) malloc(DATA_COUNT * sizeof(float));

    //Read data
    fseek(fp, 4, SEEK_CUR);
    fread(UGRD, sizeof(float), DATA_COUNT, fp);
    fseek(fp, 8, SEEK_CUR);
    fread(VGRD, sizeof(float), DATA_COUNT, fp);

    // Display JSON
    longitude = -0;
    latitude = -90;
    printf("[");
    for(i=0; i<DATA_COUNT; i++) {
        printf("{\"lon\":%d,\"lat\":%d,\"UGRD\":%f,\"VGRD\":%f}", longitude++, latitude, UGRD[i], VGRD[i]);
        if (i < DATA_COUNT-1) {
            printf(",");
        }
        if (longitude>359) {
            latitude++;
            longitude = 0;
        }
    }
    printf("]");

    // Release memory
    free(UGRD);
    free(VGRD);
    
    // close the file
    fclose(fp);

    // End
    return 0;
}