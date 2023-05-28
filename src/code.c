#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/code.h"
#include "../include/hash.h"

#define CLEAR_CODE 256
#define END_CODE 257

void initialize_dict(List* dict) {
    *dict = NULL;
    int i;
    for (i = 0; i <= 255; i++) {
        char c = (char)i;

        char* char_ptr = malloc(2 * sizeof(char)); 
        if (char_ptr == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(1);
        }
        char_ptr[0] = c;
        char_ptr[1] = '\0';

        insert(dict, char_ptr, i);
    }
    insert(dict, "CLEAR_CODE", CLEAR_CODE);
    insert(dict, "END_CODE", END_CODE);
}


void output(FILE *output_file, int code) {
    fprintf(output_file, "%d ", code);
}

void encode(FILE* input_file, FILE* output_file){
    List dict;
    initialize_dict(&dict);

    int next_code = 258;
    char last_valid[256] = "";

    output(output_file, CLEAR_CODE);
    
    char input;
    while (fscanf(input_file, "%c", &input) == 1) {
        printf("input = %c\n", input);
        /*char valid_input[256];
        strncat(valid_input, last_valid, (char)input);*/
        char valid_input[258];

        sprintf(valid_input, "%s%c", last_valid, input);

        printf("valid_input = %s\n", valid_input);

        link* found = find(dict, valid_input);
        if(found != NULL){
            strcpy(last_valid, valid_input);
            printf("OUI\n");
        } else {
            printf("NON\n");
            link *last_valid_entry = find(dict, last_valid);
            printf("last_valid = %s\n", last_valid);
            printf("%d\n", last_valid_entry->code);
            output(output_file, last_valid_entry->code);

            insert(&dict, valid_input, next_code);
            next_code++; 

            *last_valid = input;
            printf("last_valid = %s\n", last_valid);
        }
        printf("_______________\n");
    }   

    link* last_valid_entry = find(dict, last_valid);
    output(output_file, last_valid_entry->code);

    output(output_file, END_CODE);


    /*print_list(dict);*/


    free_list(dict);
}