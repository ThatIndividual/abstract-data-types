#ifndef ADT_stack_h
#define ADT_stack_h

#define T Stack_T

typedef struct T *T;

extern    T  Stack_new  (void);
extern  int  Stack_empty(T stk);
extern void  Stack_push (T stk, void *val);
extern void *Stack_pop  (T stk);
extern void  Stack_map  (T stk, void map_fun(void *val));
extern void  Stack_free (T stk);

#undef T

#endif

