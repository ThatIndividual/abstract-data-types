#include "open_hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned long hash_fun(const char*);
static struct hentry* hentry_new(const char*, int);
static void open_hash_enlarge(struct open_hash*);

struct open_hash*
open_hash_new(void)
{
    struct open_hash* hash = malloc(sizeof(struct open_hash));
    hash->size = 2;
    hash->slack = 1;
    hash->table = malloc(sizeof(struct hentry) * 3);

    return hash;
}

void
open_hash_kvpins(struct open_hash* hash, const char* key, int value)
{
    struct hentry* entry = hentry_new(key, value);
    open_hash_entins(hash, entry);
}

void
open_hash_entins(struct open_hash* hash, struct hentry* entry)
{
    unsigned long hkey;
    int probes;
    entry->dist = 0;
    for
    (
        hkey = hash_fun(entry->key) % hash->size,
        probes = 0;
        ;
        ++hkey,
        ++probes,
        ++entry->dist
    )
    {
        if (probes > hash->slack)
        {
            open_hash_enlarge(hash);
            open_hash_entins(hash, entry);
            break;
        }
        else if (hash->table[hkey] == NULL)
        {
            hash->table[hkey] = entry;
            break;
        }
        else if (hash->table[hkey]->dist < probes)
        {
            struct hentry* temp = hash->table[hkey];
            hash->table[hkey] = entry;
            entry = temp;
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
            ++hkey;
            cell = hash->table[hkey];
        }
    }
    return NULL;
}

static void
open_hash_enlarge(struct open_hash* hash)
{
    struct hentry** old_table = hash->table;
    int old_size = hash->size;
    int old_slack = hash->slack;
    hash->size *= 2;
    hash->slack += 1;
    hash->table = malloc(sizeof(struct hentry) * (hash->size + hash->slack));

    for (int i = 0; i < old_size + old_slack; ++i)
    {
        if (old_table[i] != NULL)
            open_hash_entins(hash, old_table[i]);
    }
    free(old_table);
}

void
open_hash_print(struct open_hash* hash)
{
    float items = 0.0;
    struct hentry* cell;
    for (int i = 0; i < hash->size; ++i)
    {
        cell = hash->table[i];
        if (cell == NULL)
        {
            printf("%2i: nil\n", i);
        }
        else
        {
            printf("%2i. d:%i, %s => %i\n",
                   i, cell->dist, cell->key, cell->value);
            ++items;
        }
    }
    printf("----------\n");
    for (int i = hash->size; i < hash->size + hash->slack; ++i)
    {
        cell = hash->table[i];
        if (cell == NULL)
        {
            printf("%2i: nil\n", i);
        }
        else
        {
            printf("%2i. d:%i, %s => %i\n",
                   i, cell->dist, cell->key, cell->value);
            ++items;
        }
    }

    printf("Load: %f\n\n", items / (hash->size + hash->slack));
}

static unsigned long
hash_fun(const char* key)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

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

