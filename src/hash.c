#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hash.h"

/* Création du lien */
link *create_link(link *next, char word[], int code) {
    link *lnk = malloc(sizeof(link));
    lnk->word = (char*)malloc((strlen(word) + 1) * sizeof(char));
    strcpy(lnk->word, word);
    lnk->code = code;
    lnk->next = next;
    return lnk;
}

table *create_table(int M){
    table* t = (table*)malloc(sizeof(table));
    t->M = M;
    t->size = 0;
    t->buckets = (link**)malloc(M * sizeof(link*));
    int i;
    for (i = 0; i < M; i++) {
        t->buckets[i] = NULL;
    }
    return t;
}

void free_table(table* t) {
    if (t == NULL) {
        return;
    }

    int i;
    for (i = 0; i < t->M; i++) {
        link* current = t->buckets[i];
        while (current) {
            link *tmp = current;
            current = current->next;
            free(tmp->word);
            free(tmp);
        }
    }

    free(t->buckets);

    free(t);
}

/* Affiche la list */
void display_list(link *lst) {
    while (lst) {
        printf("%s %d : ", lst->word, lst->code);
        lst = lst->next;
    }
}

/* Affiche la table avec le premier élément de chaque liste */
void display_table(table *t) {
    int i;
    for (i = 0; i < t->M; i++) {
        link *lst = t->buckets[i];
        while (lst) {
            printf("%d %s %d \n", i, lst->word, lst->code);
            lst = lst->next;
        }
    }
}

/* Fonction de hash */
unsigned hash_word(char *str, int number) {
    unsigned h = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        h = 31*h + str[i];
    }
    return h % number;
}

unsigned hash_code(int code, int number) {
    unsigned h = 0;
    h = 31*h + code;
    return h % number;
}

/* Cherche la présence d'un élément dans une liste chaînées */
link* find(table *tab, void * word, int useCode){
    unsigned index;
    if(useCode == 0){
        int wordInt = *(int*)word;
        index = hash_code(wordInt, tab->M);
    }else{
        char* wordChar = (char*)word;
        index = hash_word(wordChar, tab->M);
    }
    link* current =  tab->buckets[index];
    while (current != NULL) {
        if (useCode == 0) {
            int wordInt = *(int*)word;
            if (current->code == wordInt) {
                return current;
            }
        } else {
            char* wordChar = (char*)word;
            if (strcmp(current->word, wordChar) == 0) {
                return current;
            }
        }
        current = current->next;
    }
    return NULL;
}

/* Insérer un élément dans la table de hachage */
void insert(table* tab, char word[], int code, int useCode){
    unsigned index;
    if(useCode == 0){
        index = hash_code(code, tab->M);
    }else{
        index = hash_word(word, tab->M);
    }
    tab->buckets[index] = create_link(tab->buckets[index], word, code);
    tab->size++;
}

/* Initialisation du dictionnaire */
void initialize_dict(table* dict, int useCode) {
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

        insert(dict, char_ptr, i, useCode);
    }
    insert(dict, "CLEAR_CODE", 256, useCode);
    insert(dict, "END_CODE", 257, useCode);
}