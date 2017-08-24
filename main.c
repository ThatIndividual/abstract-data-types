#include "vector.h"

#include <stdio.h>

int
main(void)
{
    int *num, len, i;
    int i0 = 199;
    int i1 = 200;
    int i2 = 123;
    int i3 = 456;

    Vector_T vec = Vector_new(sizeof(int));
    Vector_push(vec, &i0);
    Vector_push(vec, &i1);
    Vector_push(vec, &i2);
    Vector_push(vec, &i3);

    len = Vector_length(vec);
    for (i = 0; i < len; ++i)
    {
        num = Vector_get(vec, i);
        printf("%i: %i\n", i, *num);
    }

    return 0;
}

