#include "open_hash.h"

#include <stdio.h>

int
main(void)
{
    struct open_hash* myhash = open_hash_new();
    open_hash_insert(myhash, "London", 9750);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Birmingham", 2453);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Manchester", 1903);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Glasgow", 1057);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Newcastle", 837);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Sheffield", 818);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Liverpool", 793);
    open_hash_print(myhash);
    open_hash_insert(myhash, "Leeds", 761);
    open_hash_print(myhash);

    const char* place = "Newcastle";
    printf("The population of `%s` is %i'000.\n",
           place, *open_hash_search(myhash, place));
    return 0;
}

