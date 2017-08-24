#ifndef ALG_heap_h_
#define ALG_heah_h_

#define T Heap_T

typedef struct T *T;

extern    T Heap_new  (void);
extern void Heap_add  (T heap, int data);
extern  int Heap_pop  (T heap);
extern void Heap_print(T heap);

#undef T

#endif

