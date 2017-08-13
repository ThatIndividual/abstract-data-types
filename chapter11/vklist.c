#include "vklist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vklist*
vklist_new(void)
{
    struct vk_node* sent = malloc(sizeof(struct vk_node));
    sent->next = sent;
    sent->prev = sent;

    struct vklist* list = malloc(sizeof(struct vklist));
    list->sent = sent;
    list->length = 0;

    return list;
}

void
vklist_insert(struct vklist* list, const char* key, int value)
{
    struct vk_node* node = malloc(sizeof(struct vk_node));
    node->key = key;
    node->value = value;

    node->prev = list->sent->prev;
    list->sent->prev->next = node;
    list->sent->prev = node;
    node->next = list->sent;

    ++list->length;
}

int
vklist_get(struct vklist* list, const char* key)
{
    struct vk_node* item = list->sent;
    for (int i = 0; i < list->length; ++i)
    {
        item = item->next;
        if (strcmp(key, item->key) == 0)
            return item->value;
    }

    printf("WRN: Failed to find key `%s` in the list\n", key);
}

void
vklist_print(struct vklist* list)
{
    struct vk_node* item = list->sent;

    for (int i = 0; i < list->length; ++i)
    {
        item = item->next;
        printf("`%s` => %i, ", item->key, item->value);
    }
}

