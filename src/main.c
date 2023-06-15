#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash.h"
#include "../include/decode.h"
#include "../include/code.h"
#include "../include/bit_io.h"

int main(int argc, char const *argv[])
{
    if (argc < 4) {
        printf("Usage: ./lzw <-e (encode)/ -d (decode)> <input_file> <output_file> \n");
        return 1;
    }

    const char* input_file_path = argv[2];
    const char* output_file_path = argv[3];
    const char* operation = argv[1];

    FILE* input_file = fopen(input_file_path, "r");
    FILE* output_file = fopen(output_file_path, "w");

    if (input_file == NULL|| output_file == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    if (strcmp(operation, "-e") == 0) {
        FILE* encoding_file = fopen(output_file_path, "wb");
        if (encoding_file == NULL) {
            printf("Failed to open encoding file.\n");
            return 1;
        }

        BIT_FILE* encoding_bin = bit_begin(encoding_file);

        encode(input_file, encoding_bin);

        fclose(encoding_file);
    } else if (strcmp(operation, "-d") == 0) {
        FILE* decoding_file = fopen(input_file_path, "rb");
        if (decoding_file == NULL) {
            printf("Failed to open decoding file.\n");
            return 1;
        }

        BIT_FILE* encoding_bin = bit_begin(decoding_file);

        decode(encoding_bin, output_file);

        fclose(decoding_file);
    } else {
        printf("Invalid operation. Please choose 'encode' or 'decode'.\n");
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}