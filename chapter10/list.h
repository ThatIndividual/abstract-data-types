#ifndef ALG_list_h
#define ALG_list_h

struct list
{
    struct list_node* sent;
    int length;
};

struct list_node
{
    struct list_node* next;
    struct list_node* prev;
    int data;
};

struct list* list_new(void);
void list_prepend(struct list*, int);
void list_append(struct list*, int);
int list_search(struct list*, int);

#endif

