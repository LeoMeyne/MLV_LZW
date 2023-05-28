#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hash.h"

void insert(List* lst, char word[], int code) {
    link* new_node = allocate_cell(word, code);
    new_node->next = *lst;
    *lst = new_node;
}

int find(link *lst, char word[]){
    link* current = lst;
    while (current != NULL) {
        if(strcmp(current->word, word) == 0){
            return 1;
        }
        current = current->next;
    }
    return 0;
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

void print_list(List l){
    link* current = l;
    while (current != NULL) {
        printf("%s %d\n", current->word, current->code);
        current = current->next;
    }
}

void free_list(List l){
    while (l != NULL) {
        link* next = l->next;
        
        free(l->word);
        
        free(l);
        
        l = next;
    }
}