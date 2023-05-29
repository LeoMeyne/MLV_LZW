#include <stdio.h>
#include <stdlib.h>

#include "../include/hash.h"
#include "../include/decode.h"
#include "../include/code.h"

int main(int argc, char const *argv[])
{

    FILE* input_file = fopen("./data/input.txt", "r");
    FILE* encoding_file = fopen("./data/encoding_file.txt", "w");

    if (input_file == NULL|| encoding_file == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    encode(input_file, encoding_file);

    fclose(input_file);
    fclose(encoding_file);


    encoding_file = fopen("./data/encoding_file.txt", "r");
    FILE* decoding_file = fopen("./data/decoding_file.txt", "w");

    if (encoding_file == NULL || decoding_file == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    decode(encoding_file, decoding_file);

    fclose(encoding_file);
    fclose(decoding_file);

    return 0;
}
