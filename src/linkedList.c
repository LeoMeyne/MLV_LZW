#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/linkedList.h"

/*void insert(List* lst, char word[], int code) {
    link* new_node = allocate_cell(word, code);
    new_node->next = *lst;
    *lst = new_node;
}

link* find(link *lst, char word[]){
    link* current = lst;
    while (current != NULL) {
        if(strcmp(current->word, word) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

link* find_int(link *lst, int code){
    link* current = lst;
    while (current != NULL) {
        if(current->code == code){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

link* allocate_cell(char word[], int code){
    link* new_link = (link*)malloc(sizeof(link));
    new_link->word = (char*)malloc((strlen(word) + 1) * sizeof(char));

    strcpy(new_link->word, word);

    new_link->code = code;
    new_link->next = NULL;

    return new_link;
}

void print_list(List list){
    link* current = list;
    while (current != NULL) {
        printf("%s %d\n", current->word, current->code);
        current = current->next;
    }
}

void free_list(List list){
    while (list != NULL) {
        link* next = list->next;
        free(list->word);
        free(list);
        list = next;
    }
}

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
}*/