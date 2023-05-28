#ifndef HASH_H
#define HASH_H

typedef struct _link {
    char *word;
    int code;
    struct _link *next;
} link, *List;

/*typedef struct _table {
    link **buckets;
    int M; 
    int size;
} table;*/

void insert(List* lst, char word[], int code);
link* find(link *lst, char word[]);
link* find_int(link *lst, int code);
link* allocate_cell(char word[], int code);
void free_list(List list);
void print_list(List list);

#endif