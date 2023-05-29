#include <stdio.h>
#include <stdlib.h>

#include "../include/hash.h"
#include "../include/decode.h"
#include "../include/code.h"
#include "../include/bit_io.h"

int main(int argc, char const *argv[])
{

    FILE* input_file = fopen("./data/input.txt", "r");
    FILE* encoding_file = fopen("./data/encoding_file.bin", "w");

    if (input_file == NULL|| encoding_file == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    BIT_FILE* encoding_bin = bit_begin(encoding_file);



    encode(input_file, encoding_bin);

    fclose(input_file);
    fclose(encoding_file);


    encoding_file = fopen("./data/encoding_file.bin", "r");
    FILE* decoding_file = fopen("./data/decoding_file.txt", "w");

    if (encoding_file == NULL || decoding_file == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    encoding_bin = bit_begin(encoding_file);

    decode(encoding_bin, decoding_file);

    fclose(encoding_file);
    fclose(decoding_file);

    return 0;
}
