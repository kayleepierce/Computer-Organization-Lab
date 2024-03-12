/*
 * Kaylee Pierce
 * CPSC 2311-002
 */

#include "ppmUtil.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_filename output_filename\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Error opening input file %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        printf("Error opening output file %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    header_t header;
    pixel_t *pixels = read(input, &header);

    write(output, header, pixels);

    freeMemory(pixels);

    fclose(input);
    fclose(output);

    return 0;
}
