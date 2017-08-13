#include "hash.h"

#include <stdio.h>

int
main(void)
{
    struct hash* myhash = hash_new();
    hash_insert(myhash, "London", 9750);
    hash_insert(myhash, "Birmingham", 2453);
    hash_insert(myhash, "Manchester", 1903);
    hash_insert(myhash, "Glasgow", 1057);
    hash_insert(myhash, "Newcastle", 837);
    hash_insert(myhash, "Sheffield", 818);
    hash_insert(myhash, "Liverpool", 793);
    hash_insert(myhash, "Leeds", 761);
    hash_print(myhash);

    const char* place = "Newcastle";
    printf("The population of `%s` is %i'000.\n",
           place, hash_get(myhash, place));
    return 0;
}

