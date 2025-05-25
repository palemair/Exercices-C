#include <stdio.h>
#include <c-xtools.h>

/* PGCD SEDGEWICK */
int pgcd (int u, int v)
{
    int count = 0;

    while (u > 0)
    {
        if (u < v)
        {
            count += 4;
            int t = u;

            u = v;
            v = t;
        }
        count += 2;
        u = u - v;
    }
    printf ("count %d -> u : %d v : %d\n", count, u, v);
    return v;
}

/* PGCD % */
int pgcd1 (int u, int v)
{
    int r;
    int count = 1;

    if (u < v)
    {
        count += 4;
        int temp = u;

        u = v;
        v = temp;
    }

    while ((r = u % v) > 0)
    {
        count += 3;
        u = v;
        v = r;
    }
    printf ("count %d -> u : %d v : %d\n", ++count, u, v);
    return v;
}

int main (void)
{

    START;
    printf ("pgcd : %d\n\n", pgcd (12345,56789));
    STOP;
    TPS ("pgcd euclide");

    return 0;
}
