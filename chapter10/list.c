#include "list.h"

#include <stdlib.h>

struct list*
list_new(void)
{
    struct list_node* sent = malloc(sizeof(struct list_node));
    sent->next = sent;
    sent->prev = sent;

    struct list* list = malloc(sizeof(struct list));
    list->sent = sent;
    list->length = 0;

    return list;
}

void
list_prepend(struct list* list, int data)
/* LIST-INSERT(L, x)
1  x.next = L.nil.next
2  L.nil.next.prev = x
3  L.nil.next = x
4  x.prev = L.nil                                                            */
{
    struct list_node* node = malloc(sizeof(struct list_node));
    node->data = data;

    node->next = list->sent->next;
    list->sent->next->prev = node;
    list->sent->next = node;
    node->prev = list->sent;

    ++list->length;
}

void
list_append(struct list* list, int data)
{
    struct list_node* node = malloc(sizeof(struct list_node));
    node->data = data;

    node->prev = list->sent->prev;
    list->sent->prev->next = node;
    list->sent->prev = node;
    node->next = list->sent;

    ++list->length;
}

int
list_search(struct list* list, int data)
{
    struct list_node* item = list->sent;
    for (int i = 0; i < list->length; ++i)
    {
        item = item->next;
        if (data == item->data)
            return i;
    }

    return -1;
}

