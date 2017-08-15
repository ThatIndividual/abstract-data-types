#include "open_hash.h"

#include <stdio.h>

struct imdbscore
{
    const char* name;
    int score;
};

struct imdbscore top40[] =
{
    { "The Shawshank Redemption", 92 },
    { "The Godfather", 92 },
    { "The Godfather: Part II", 90},
    { "The Dark Knight", 90 },
    { "12 Angry Men", 89 },
    { "Schindler's List", 89 },
    { "Pulp Fiction", 89 },
    { "The Lord of the Rings: The Resturn of the King", 89 },
    { "The Good, the Bad and the Ugly", 88 },
    { "Fight Club", 88 },
    { "The Lord of the Rings: The Fellowship of the Ring", 88 },
    { "Forrest Gump", 87 },
    { "Star Wars: Episode V - The Empire Strikes Back", 87 },
    { "Inception", 87 },
    { "The Lord of the Rings: The Two Towers", 87 },
    { "One Flew Over the Cuckoo's Nest", 87 },
    { "Goodfellas", 87 },
    { "The Matrix", 87 },
    { "Seven Samurai", 86},
    { "Star Wars: Episode IV - A New Hope", 86 },
    { "City of God", 86 },
    { "Se7en", 86 },
    { "The Silence of the Lambs", 86 },
    { "It's a Wonderful Life", 86 },
    { "Life is Beautiful", 86 },
    { "The Usual Suspects", 86 },
    { "Leon", 85 },
    { "Saving Private Ryan", 85 },
    { "Spirited Away", 85 },
    { "Once Upon a Time in the West", 85 },
    { "American History X", 85 },
    { "Interstellar", 85 },
    { "Psycho", 85 },
    { "Casablanca", 85 },
    { "City Lights", 85 },
    { "The Green Mile", 85 },
    { "Untouchable", 85 },
    { "Modern Times", 85 },
    { "Raiders of the Lost Ark", 85 },
    { "The Pianist", 85 }
};

int
main(void)
{
    struct open_hash* myhash = open_hash_new();
    for (int i = 0; i < 40; ++i)
    {
        printf("Inserting `%s`:\n", top40[i].name);
        open_hash_insert(myhash, top40[i].name, top40[i].score);
        open_hash_print(myhash);
    }
    open_hash_print(myhash);

    return 0;
}

