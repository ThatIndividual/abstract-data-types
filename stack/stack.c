#include <assert.h>
#include <stdlib.h>
#include "stack.h"

#define T Stack_T

struct T
{
    int count;
    struct elem
    {
        void *x;
        struct elem *link;
    } *head;
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
Stack_push(T stk, void *x)
{
    struct elem *t;

    assert(stk);
    t = malloc(sizeof(struct elem));
    t->x = x;
    t->link = stk->head;
    stk->head = t;
    ++stk->count;
}

void *
Stack_pop(T stk)
{
    void *x;
    struct elem *t;

    assert(stk);
    assert(stk->count > 0);
    t = stk->head;
    stk->head = t->link;
    --stk->count;
    x = t->x;
    free(t);

    return x;
}

