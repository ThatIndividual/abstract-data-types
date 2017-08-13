#include "dblist.h"

#include <stdlib.h>

struct dblist*
dblist_new(void)
{
    struct dblist_node* sent = malloc(sizeof(struct dblist_node));
    sent->next = sent;
    sent->prev = sent;

    struct dblist* dblist = malloc(sizeof(struct dblist));
    dblist->sent = sent;
    dblist->length = 0;

    return dblist;
}

void
dblist_prepend(struct dblist* dblist, int data)
/* LIST-INSERT(L, x)
1  x.next = L.nil.next
2  L.nil.next.prev = x
3  L.nil.next = x
4  x.prev = L.nil                                                            */
{
    struct dblist_node* node = malloc(sizeof(struct dblist_node));
    node->data = data;

    node->next = dblist->sent->next;
    dblist->sent->next->prev = node;
    dblist->sent->next = node;
    node->prev = dblist->sent;

    ++dblist->length;
}

void
dblist_append(struct dblist* dblist, int data)
{
    struct dblist_node* node = malloc(sizeof(struct dblist_node));
    node->data = data;

    node->prev = dblist->sent->prev;
    dblist->sent->prev->next = node;
    dblist->sent->prev = node;
    node->next = dblist->sent;

    ++dblist->length;
}

int
dblist_search(struct dblist* dblist, int data)
{
    struct dblist_node* item = dblist->sent;
    for (int i = 0; i < dblist->length; ++i)
    {
        item = item->next;
        if (data == item->data)
            return i;
    }

    return -1;
}

