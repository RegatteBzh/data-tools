/**
 * Tool to convert wind forecast (1deg) bin file to json
 *
 * Cyrille Meichel <cmeichel@free.fr> 2016/11
 *
 **/

#include <stdio.h>
#include <malloc.h>
#include <stdint.h>

/**
 * @param count Number of samples
 * @param fp    File
 * @returns Buffer (array of floats)
 */
float* readBlock(uint32_t* count, FILE* fp) {
    float* buffer;
    uint32_t size;

    // Get the size of the data segment
    fread(&size, sizeof(uint32_t), 1, fp);

    // Prepare buffer
    buffer = (float*)malloc(size);
    *count = size / sizeof(float);

    // Read the buffer
    fread(buffer, sizeof(float), *count, fp);

    return buffer;
}

int main (int argc, char** argv) {
    FILE* fp;
    char* filename;
    float* UGRD;
    float* VGRD;
    uint32_t i;
    int longitude;
    int latitude;
    uint32_t countUgrd;
    uint32_t countVgrd;
    uint32_t count;

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

    UGRD = readBlock(&countVgrd, fp);
    VGRD = readBlock(&countUgrd, fp);
    count = (countVgrd > countUgrd) ? countUgrd : countVgrd;

    // Display JSON
    longitude = -0;
    latitude = -90;
    printf("[");
    for(i=0; i<count; i++) {
        printf("{\"lon\":%d,\"lat\":%d,\"UGRD\":%f,\"VGRD\":%f}", longitude++, latitude, UGRD[i], VGRD[i]);
        if (i < count-1) {
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