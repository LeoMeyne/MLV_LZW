#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/code.h"
#include "../include/hash.h"

#define CLEAR_CODE 256
#define END_CODE 257

#define USECODE 1

void output(FILE *output_file, int code) {
    fprintf(output_file, "%d ", code);
}

void encode(FILE* input_file, FILE* output_file){
    table* dict = create_table(5);
    initialize_dict(dict, USECODE);

    /*display_table(dict);*/

    int next_code = 258;
    char last_valid[256] = "";

    output(output_file, CLEAR_CODE);
    
    char input;
    while (fscanf(input_file, "%c", &input) == 1) {
        char valid_input[258];

        sprintf(valid_input, "%s%c", last_valid, input);

        link* found = find(dict, valid_input, USECODE);
        if(found != NULL){
            strcpy(last_valid, valid_input);
        } else {
            link *last_valid_entry = find(dict, last_valid, USECODE);
            output(output_file, last_valid_entry->code);

            insert(dict, valid_input, next_code, USECODE);
            next_code++; 

            strncpy(last_valid, &input, 1);
            last_valid[1] = '\0'; 
        }
    }   

    link* last_valid_entry = find(dict, last_valid, USECODE);
    output(output_file, last_valid_entry->code);

    output(output_file, END_CODE);
    
    free_table(dict);
}