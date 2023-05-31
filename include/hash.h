#ifndef HASH_H
#define HASH_H

typedef struct _link {
    char *word;
    int code;
    struct _link *next;
} link, *List;

typedef struct _table {
    link **buckets;
    int M; 
    int size;
} table;

link *create_link(link *lst, char word[], int code);

table *create_table(int M);

void display_list(link *lst);

void display_table(table *t);

void free_link(link *lnk);

void free_list(link *lst);

link* find(table* tab, char* key, int useCode);

void insert(table* tab, char word[], int code, int useCode);

void initialize_dict(table* dict, int useCode);

void free_table(table* t) ;

#endif