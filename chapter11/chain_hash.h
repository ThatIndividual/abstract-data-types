#ifndef ALG_chain_hash_h
#define ALG_chain_hash_h

#include "vklist.h"

struct hash
{
    struct vklist** table;
    int size;
    int items;
};

struct hash* hash_new(void);
void hash_insert(struct hash*, const char*, int);
int hash_get(struct hash*, const char*);
void hash_print(struct hash*);

#endif

