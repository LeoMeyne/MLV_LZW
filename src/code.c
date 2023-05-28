#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/code.h"
#include "../include/hash.h"

void initialize_dict(List* dict) {
    *dict = NULL;
    int i;
    for(i = 0; i <= 255; i++){
        char c = (char)i;
        insert(dict, &c, i);
    }
}

void encode(FILE* input_file, FILE* output_file){
    List dict;
    initialize_dict(&dict);

    print_list(dict);

    free_list(dict);
}