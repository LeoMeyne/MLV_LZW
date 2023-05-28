#include <stdio.h>
#include <stdlib.h>

#include "../include/hash.h"
#include "../include/decode.h"

int main(int argc, char const *argv[])
{

    FILE* input_file = fopen("./data/input.txt", "r");
    FILE* output_file = fopen("./data/output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    decode(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
