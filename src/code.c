#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/code.h"
#include "../include/hash.h"

#define CLEAR_CODE 256
#define END_CODE 257

void output(FILE *output_file, int code) {
    fprintf(output_file, "%d ", code);
}

void encode(FILE* input_file, BIT_FILE* output_file){
    List dict = NULL;
    initialize_dict(&dict);

    int next_code = 258;
    char last_valid[256] = "";

    bit_put(output_file, CLEAR_CODE, 9);
    
    char input;
    while (fscanf(input_file, "%c", &input) == 1) {
        char valid_input[258];

        sprintf(valid_input, "%s%c", last_valid, input);

        link* found = find(dict, valid_input);
        if(found != NULL){
            strcpy(last_valid, valid_input);
        } else {
            link *last_valid_entry = find(dict, last_valid);
            bit_put(output_file, last_valid_entry->code, 9);
            
            if(next_code != 512){
                insert(&dict, valid_input, next_code);
                next_code++; 
            }
            else{
                bit_put(output_file, CLEAR_CODE, 9);
                initialize_dict(&dict);
                next_code = 258;
            }

            strncpy(last_valid, &input, 1);
            last_valid[1] = '\0'; 
        }
    }   

    link* last_valid_entry = find(dict, last_valid);
    bit_put(output_file, last_valid_entry->code, 9);

    bit_put(output_file, END_CODE, 9);

    free_list(dict);
}