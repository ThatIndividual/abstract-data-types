#include "open_hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned long hash_fun(const char*);
static struct hentry* hentry_new(const char*, int);

struct open_hash*
open_hash_new(void)
{
    struct open_hash* hash = malloc(sizeof(struct open_hash));
    hash->size = 41;
    hash->free = 41;
    hash->table = malloc(sizeof(struct hentry) * hash->size);

    return hash;
}

void
open_hash_insert(struct open_hash* hash, const char* key, int value)
{
    unsigned long hkey = hash_fun(key) % hash->size;
    struct hentry* new_entry = hentry_new(key, value);
    for
    (
        int probes = 0;
        ;
        hkey = (hkey + 1) % hash->size,
        ++new_entry->dist,
        ++probes
    )
    {
        if (hash->table[hkey] == NULL)
        {
            hash->table[hkey] = new_entry;
            break;
        }
        else if(hash->table[hkey]->dist < probes)
        {
            struct hentry* temp = hash->table[hkey];
            hash->table[hkey] = new_entry;
            new_entry = temp;
        }
    }
}

int*
open_hash_search(struct open_hash* hash, const char* key)
{
    unsigned long hkey = hash_fun(key) % hash->size;
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
            printf("%2i: nil\n", i);
        else
            printf("%2i. d:%i, %s => %i\n",
                   i, cell->dist, cell->key, cell->value);
    }
    putchar('\n');
}

static unsigned long
hash_fun(const char* key)
{
    unsigned long hash = 0;

    for (const char* c = key; *c != '\0'; ++c)
        hash = hash * 33 + *c;

    return hash;
}

static struct hentry*
hentry_new(const char* key, int value)
{
    struct hentry* entry = malloc(sizeof(struct hentry));
    entry->dist = 0;
    entry->key = key;
    entry->value = value;

    return entry;
}

