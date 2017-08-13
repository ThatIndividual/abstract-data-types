#ifndef ALG_dblist_h
#define ALG_dblist_h

struct dblist
{
    struct dblist_node* sent;
    int length;
};

struct dblist_node
{
    struct dblist_node* next;
    struct dblist_node* prev;
    int data;
};

struct dblist* dblist_new(void);
void dblist_prepend(struct dblist*, int);
void dblist_append(struct dblist*, int);
int dblist_search(struct dblist*, int);

#endif

