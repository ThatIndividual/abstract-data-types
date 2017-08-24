struct sglist
{
    struct sgnode* sent;
    int length;
};

struct sgnode
{
    struct sgnode* next;
    int data;
};

struct sglist* sglist_new(void);
void sglist_prepend(struct sglist*, int);
int sglist_search(struct sglist*, int);
void sglist_print(struct sglist*);

