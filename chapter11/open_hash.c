#include "open_hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long hash_fun(const char*);

struct open_hash*
open_hash_new(void)
{
    struct open_hash* hash = malloc(sizeof(struct open_hash));
    hash->size = 10;
    hash->free = 10;
    hash->table = malloc(sizeof(struct hentry) * hash->size);

    return hash;
}

void
open_hash_insert(struct open_hash* hash, const char* key, int value)
{
    long hkey = hash_fun(key) % hash->size;
    struct hentry* new_entry = malloc(sizeof(struct hentry));

    new_entry->key = key;
    new_entry->value = value;
    while (hash->table[hkey] != NULL)
        hkey = (hkey + 1) % hash->size;

    hash->table[hkey] = new_entry;
}

int*
open_hash_search(struct open_hash* hash, const char* key)
{
    long hkey = hash_fun(key) % hash->size;
    struct hentry* cell = hash->table[hkey];
    while (cell != NULL)
    {
        if (strcmp(cell->key, key) == 0)
            return &cell->value;
        else
        {
            hkey = (hkey + 1) % hash->size;
            cell = hash->table[hkey];
        }
    }
    return NULL;
}

void
open_hash_print(struct open_hash* hash)
{
    struct hentry* cell;
    for (int i = 0; i < hash->size; ++i)
    {
        cell = hash->table[i];
        if (cell == NULL)
            printf("%i: nil\n", i);
        else
            printf("%i: %s => %i\n", i, cell->key, cell->value);
    }
    putchar('\n');
}

static long
hash_fun(const char* key)
{
    long hash = 0;

    for (const char* c = key; *c != '\0'; ++c)
        hash = hash * 33 + *c;

    return hash;
}

