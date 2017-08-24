#include <stdio.h>
#include "heap.h"

// 2695821851057213851726

int
main(void)
{
    Heap_T h;

    h = Heap_new();

    Heap_add(h, 210);
    Heap_add(h, 948);
    Heap_add(h, 721);
    Heap_add(h, 834);
    Heap_add(h, 762);
    Heap_add(h, 150);
    Heap_add(h, 124);
    Heap_add(h, 512);
    Heap_add(h,  95);
    Heap_add(h, 621);
    Heap_add(h, 587);
    Heap_add(h, 409);
    Heap_add(h, 375);
    Heap_add(h, 269);
    Heap_add(h,  57);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    Heap_pop(h);
    Heap_print(h);

    return 0;
}

