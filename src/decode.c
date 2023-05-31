#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/linkedList.h"

/*void decode(FILE* input_file, FILE* output_file){
    List dict = NULL;
    int code;

    int next_code = 258;
    char* last_valid = NULL;
    char* seq = NULL;

    while(fscanf(input_file, "%d", &code) == 1){

        if(code == 256){
            initialize_dict(&dict);
            next_code = 258;
            last_valid = NULL;
            continue;
        }

        if(code == 257){
            break;
        }

        if(find_int(dict, code) != NULL){
            char* found = find_int(dict, code)->word;
            seq = malloc((strlen(found) + 1) * sizeof(char));
            strcpy(seq, found);
        }
        else{
            char str[2];
            str[0] = last_valid[0];
            str[1] = '\0';
            seq = strcat(last_valid, str);
        }

        fprintf(output_file, "%s", seq);
        fprintf(output_file, "%s", "");


        if(last_valid != NULL){
            char str[2];
            str[0] = seq[0];
            str[1] = '\0';
            insert(&dict,strcat(last_valid, str), next_code);
            next_code ++; 
        }

        last_valid = seq;
    }

    free(dict);
}   */