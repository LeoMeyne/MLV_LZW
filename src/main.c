#include <stdio.h>
#include <stdlib.h>

#include "../include/hash.h"

int main(int argc, char const *argv[])
{
    List list = NULL;
    int i;
    for(i = 0; i < 5; i++){
        insert(&list, "yo", i);   
    }

    print_list(list);

    printf("%d\n", find(list, "yo"));

    return 0;
}
