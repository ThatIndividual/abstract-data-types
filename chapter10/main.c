#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    struct list* the_list = list_new();
    list_append(the_list, 5);
    list_append(the_list, 10);
    list_prepend(the_list, 15);
    list_prepend(the_list, 20);

    struct list_node* item = the_list->sent;
    for (int i = 0; i < the_list->length; ++i)
    {
        item = item->next;
        printf("Item %i: %i,\n", i, item->data);
    }

    printf("%i is at pos %i\n", 5, list_search(the_list, 5));
    printf("%i is at pos %i\n", 20, list_search(the_list, 20));
    printf("%i is at pos %i\n", 7, list_search(the_list, 7));

    return 0;
}

