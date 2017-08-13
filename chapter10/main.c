#include "sglist.h"

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    struct sglist* mylist = sglist_new();
    sglist_prepend(mylist, 10);
    sglist_prepend(mylist, 25);
    sglist_prepend(mylist, 61);
    sglist_prepend(mylist, 82);
    sglist_prepend(mylist, 45);
    sglist_prepend(mylist, 20);

    sglist_print(mylist);

    return 0;
}

