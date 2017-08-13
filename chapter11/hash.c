#include "hash.h"
#include "vklist.h"

#include <stdlib.h>
#include <stdio.h>

static long hash_fun(const char*);

struct hash*
hash_new(void)
{
    struct hash* hash = malloc(sizeof(struct hash));
    struct vklist** table = malloc(sizeof(struct vklist*) * 10);

    hash->table = table;
    hash->size = 11;
    hash->items = 0;

    return hash;
}

void
hash_insert(struct hash* hash, const char* key, int value)
{
    long hkey = hash_fun(key) % hash->size;

    if (hash->table[hkey] == NULL)
        hash->table[hkey] = vklist_new();
    vklist_insert(hash->table[hkey], key, value);
    ++hash->items;
}

int
hash_get(struct hash* hash, const char* key)
{
    long hkey = hash_fun(key) % hash->size;
    return vklist_get(hash->table[hkey], key);
}

long
hash_fun(const char* key)
{
    long hash = 0;

    for (const char* c = key; *c != '\0'; ++c)
        hash = hash * 33 + *c;

    return hash;
}

void
hash_print(struct hash* hash)
{
    for (int i = 0; i < hash->size; ++i)
    {
        printf("Cell %i: ", i);
        if (hash->table[i] == NULL)
            printf("NONE");
        else
            vklist_print(hash->table[i]);
        putchar('\n');
    }
}

