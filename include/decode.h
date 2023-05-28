#ifndef DECODE_H
#define DECODE_H

#include "hash.h"

void initialize_dict(List* list);
void decode(FILE* input_file, FILE* output_file);

#endif