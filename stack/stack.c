#include <assert.h>
#include <stdlib.h>
#include "stack.h"

#define T Stack_T

struct T
{
    struct elem
    {
        void *data;
        struct elem *link;
    } *head;
    int count;
};

T
Stack_new(void)
/* XXX this could optionally receive a maximum stack size argument. max < 1
   would be interpreted as "infinite size"                                   */
{
    T stk;

    stk = malloc(sizeof(struct T));
    stk->count = 0;
    stk->head = NULL;
    return stk;
}

int
Stack_empty(T stk)
{
    assert(stk);

    return stk->count == 0;
}

void
Stack_push(T stk, void *data)
{
    struct elem *t;

    assert(stk);

    t = malloc(sizeof(struct elem));
    t->data = data;
    t->link = stk->head;
    stk->head = t;
    ++stk->count;
}

void *
Stack_pop(T stk)
{
    void *data;
    struct elem *t;

    assert(stk);
    assert(stk->count > 0);

    t = stk->head;
    stk->head = t->link;
    --stk->count;
    data = t->data;
    free(t);

    return data;
}

void
Stack_map(T stk, void map_fun(void *val))
{
    struct elem *elem;

    for (elem = stk->head; elem; elem = elem->link)
        map_fun(elem->data);
}

void
Stack_free(T stk)
{
    struct elem *this_elem, *next_elem;

    assert(stk);

    for (this_elem = stk->head; this_elem; this_elem = next_elem)
    {
        next_elem = this_elem->link;
        free(this_elem);
    }
    free(stk);
}

