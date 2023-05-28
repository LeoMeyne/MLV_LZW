#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash.h"


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

    insert(dict, "CLEAR_CODE", 256);
    insert(dict, "END_CODE", 257);
}

void write(FILE* file, char* str){

}

void decode(FILE* input_file, FILE* output_file){
    List dict = NULL;
    int code;

    int next_code;
    char* last_valid;
    char* seq;

    while(fscanf(input_file, "%d", &code) == 1){

        if(code == 256){
            initialize_dict(&dict);
            next_code = 258;
            last_valid = "";
            continue;
        }

        if(code == 257){
            break;
        }

        if(find_int(dict, code) != NULL){
            seq = find_int(dict, code)->word;
        }
        else{
            char str[2];
            str[0] = last_valid[0];
            str[1] = '\0';
            seq = strcat(last_valid, str);
        }

        fprintf(output_file, "%s", seq);
        fprintf(output_file, "%s", " ");


        if(strcmp(last_valid, "") != 0){

            char str[2];
            str[0] = seq[0];
            str[1] = '\0';
            insert(&dict,strcat(last_valid, str), next_code);
            next_code ++; 
        }

        last_valid = seq;
    }

}