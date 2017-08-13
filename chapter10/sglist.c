#include "sglist.h"

#include <stdlib.h>
#include <stdio.h>

struct sglist*
sglist_new(void)
{
    struct sgnode* sent = malloc(sizeof(struct sgnode));
    sent->next = sent;

    struct sglist* sglist = malloc(sizeof(struct sglist));
    sglist->sent = sent;
    sglist->length = 0;

    return sglist;
}

void
sglist_prepend(struct sglist* sglist, int data)
{
    struct sgnode* node = malloc(sizeof(struct sgnode));
    node->data = data;

    node->next = sglist->sent->next;
    sglist->sent->next = node;

    ++sglist->length;
}

int
sglist_search(struct sglist* sglist, int data)
{
    struct sgnode* item = sglist->sent;
    for (int i = 0; i < sglist->length; ++i)
    {
        item = item->next;
        if (data == item->data)
            return i;
    }

    return -1;
}

void
sglist_print(struct sglist* sglist)
{
    struct sgnode* item = sglist->sent;
    printf("nil => ");
    for (int i = 0; i < sglist->length; ++i)
    {
        item = item->next;
        printf("%i : %i => ", i, item->data);
    }
    printf("nil\n");
}

