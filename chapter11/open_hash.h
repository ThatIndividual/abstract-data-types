#ifndef ALG_open_hash_h
#define ALG_open_hash_h

struct open_hash
{
    struct hentry* nil; /* This is our tombstone value */
    int size;
    int free;
    struct hentry** table;
};

struct hentry
{
    const char* key;
    int value;
};

struct open_hash* open_hash_new(void);
void open_hash_insert(struct open_hash*, const char*, int);
int* open_hash_search(struct open_hash*, const char*);
void open_hash_print(struct open_hash*);

#endif

