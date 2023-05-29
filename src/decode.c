#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash.h"

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