#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "../include/hash.h"
#include "../include/bit_io.h"

#define USECODE 0

void decode(BIT_FILE* input_file, FILE* output_file){
    table* dict = create_table(50);
    uint32_t code;

    int next_code = 258;
    int min_code_size = 9;
    int max_code_size = 12;
    int current_code_size = min_code_size + 1;

    char* last_valid = NULL;
    char* seq = NULL;

    while(bit_get(input_file, &code, 9) != EOF){

        if(code == 256){
            initialize_dict(dict, USECODE);
            next_code = 258;
            last_valid = NULL;
            continue;
        }

        if(code == 257){
            break;
        }

        if(find(dict, &code, USECODE) != NULL){
            char* found = find(dict, &code, USECODE)->word;
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

        if(last_valid != NULL){
            char str[2];
            str[0] = seq[0];
            str[1] = '\0';
            insert(dict,strcat(last_valid, str), next_code, USECODE);
            next_code ++; 
            if(next_code == (2^ max_code_size)){
                current_code_size++;
            }
        }

        last_valid = seq;
    }

    free(dict);
} 
