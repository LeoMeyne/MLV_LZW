#define HASH_H
#ifdef HASH_H

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
int find(link *lst, char word[]);
link* allocate_cell(char word[], int code);
void free_list(List l);
void print_list(List l);

#endif