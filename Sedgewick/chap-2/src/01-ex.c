#include <stdio.h>

/* PGCD SEDGEWICK */
int pgcd (int u, int v)
{
    int t;

    while (u > 0)
    {
        if (u < v)
        {
            t = u;
            u = v;
            v = t;
        }
        u = u - v;
    }
    return v;
}

int main (void)
{
    puts ("Exercice 1 : PGCD, version euclide");

    struct point
    {
        int x, y;
    };

    struct point tab[] = { {5, 3}, {-5, 8}, {39, 65}, {461952, 116298} };

    for (int i = 0; i < 4; i++)
        printf ("%d %d = pgcd %d\n", tab[i].x, tab[i].y, pgcd (tab[i].x, tab[i].y));

    return 0;
}
