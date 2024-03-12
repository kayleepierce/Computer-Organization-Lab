/*
 * Kaylee Pierce
 * CPSC 2311-002
 */

#include "ppmUtil.h"

//Read the header information and return pointer to pixel data
pixel_t* read(FILE* input, header_t* header) {
    readHeader(input, header); 
    return readPixels(input, *header);
}

void readHeader(FILE* input, header_t* header) {
    // Read PPM file type
    fscanf(input, "%2s", header->type);
    ckComment(input);

    // Read width
    fscanf(input, "%u", &header->width);
    ckComment(input);

    // Read height
    fscanf(input, "%u", &header->height);
    ckComment(input);

    // Read maxVal
    fscanf(input, "%u", &header->maxVal);

    fgetc(input);
}

//Allocate memory for pixels, read pixel data, and return pixels pointer
pixel_t* readPixels(FILE* input, header_t header) {
    pixel_t* pixels = allocatePixMemory(header);
    fread(pixels, sizeof(pixel_t), header.width * header.height, input);
    return pixels;
}

void writeHeader(FILE* output, header_t header) {
    fprintf(output, "%2s\n", header.type);
    fprintf(output, "%u\n", header.width);
    fprintf(output, "%u\n", header.height);
    fprintf(output, "%u\n", header.maxVal);
}

//Wrtie the pixel data to the output file
void writePixels(FILE* output, pixel_t* pixels, header_t header) {
    fwrite(pixels, sizeof(pixel_t), header.width * header.height, output);
}

//Write header information and write pixel data
void write(FILE* output, header_t header, pixel_t* pixels) {
    writeHeader(output, header);
    writePixels(output, pixels, header);
}

//Allocate memory for pixels
pixel_t* allocatePixMemory(header_t header) {
    return (pixel_t*) malloc(sizeof(pixel_t) * header.width * header.height);
}

//Free memory for allocated pixels
void freeMemory(pixel_t* pixels) {
    free(pixels);
}
//Ignore comments
void ckComment(FILE* input) {
    int c;
    
    while ((c = getc(input)) == '#' || isspace(c)) {
        if (c == '#') {
            while ((c = getc(input)) != '\n' && c != EOF) {
            }
        }
    }

    if (c != EOF) {
        ungetc(c, input);
    }
}
