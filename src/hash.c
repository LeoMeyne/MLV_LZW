#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash.h"

void insert(List* lst, char word[], int code) {
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

link* allocate_cell(char word[], int code){
    /* Allouer de la mémoire pour la nouvelle cellule */
    link* new_link = (link*)malloc(sizeof(link));

    /* Allouer de la mémoire pour chaque champs */
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