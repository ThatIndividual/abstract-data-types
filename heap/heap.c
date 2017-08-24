#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

#define T Heap_T

struct T
{
    int  *data;
    int   capacity;
    int   length;
    int   next;
};

static void Heap_grow       (T heap);
static void Heap_print_child(T heap, int cell_pos, int indent);

static inline int Heap_parent_pos(int cell_pos);
static inline int Heap_left_pos  (int cell_pos);
static inline int Heap_right_pos (int cell_pos);

T
Heap_new(void)
{
    T heap;

    heap = malloc(sizeof(struct T));
    heap->capacity = 2;
    heap->length = 0;
    heap->next = 0;
    heap->data = calloc(2, sizeof(int));

    return heap;
}

void
Heap_add(T heap, int data)
{
    int *parent, *cell, parent_pos, cell_pos;

    if (heap->next >= heap->capacity)
        Heap_grow(heap);

    *(heap->data + heap->next) = data;
    cell_pos = heap->next;
    while (cell_pos > 0)
    {
        parent_pos = Heap_parent_pos(cell_pos);
        parent = heap->data + parent_pos;
        cell = heap->data + cell_pos;

        if (*parent > *cell)
            break;
        else
        {
            int temp;

            temp = *cell;
            *cell = *parent;
            *parent = temp;
        }
        cell_pos = parent_pos;
    }

    ++heap->next;
    ++heap->length;
}

int
Heap_pop(T heap)
{
    int *left, *right, cell_pos, left_pos, right_pos, largest_pos, head;

    --heap->next;
    --heap->length;

    head = *(heap->data);
    *(heap->data) = *(heap->data + heap->next);
    cell_pos = 0;
    for (;;)
    {
        left_pos = Heap_left_pos(cell_pos);
        right_pos = left_pos + 1;
        largest_pos = cell_pos;

        if (left_pos <= heap->length)
        {
            left = heap->data + left_pos;
            if (*left > *(heap->data + largest_pos))
                largest_pos = left_pos;
        }

        if (right_pos <= heap->length)
        {
            right = heap->data + right_pos;
            if (*right > *(heap->data + largest_pos))
                largest_pos = right_pos;
        }

        if (largest_pos != cell_pos)
        {
            int temp, *cell;

            cell = heap->data + cell_pos;
            temp = *(heap->data + largest_pos);
            *(heap->data + largest_pos) = *cell;
            *cell = temp;

            cell_pos = largest_pos;
        }
        else
            break;
    }

    return head;
}

void
Heap_print(T heap)
{
    puts("== Heap ==");
    Heap_print_child(heap, 0, 0);
    puts("==========\n");
}

static void
Heap_print_child(T heap, int cell_pos, int indent)
{
    if (cell_pos < heap->next)
    {
        int i;

        for (i = 0; i < indent; ++i)
            putchar(' ');
        printf("%i\n", *(heap->data + cell_pos));

        Heap_print_child(heap, Heap_left_pos(cell_pos), indent + 2);
        Heap_print_child(heap, Heap_right_pos(cell_pos), indent + 2);
    }
}

static void
Heap_grow(T heap)
{
    heap->capacity *= 2;
    heap->data = realloc(heap->data, heap->capacity * sizeof(int));
}

static inline int
Heap_parent_pos(int cell_pos)
{
    return (cell_pos - 1) / 2;
}

static inline int
Heap_left_pos(int cell_pos)
{
    return cell_pos * 2 + 1;
}

static inline int
Heap_right_pos(int cell_pos)
{
    return cell_pos * 2 + 2;
}

#undef T

