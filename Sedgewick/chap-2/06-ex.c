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
            printf ("u : %d v : %d\n",  u, v);
            count += 4;
            int t = u;

            u = v;
            v = t;
        }
        printf ("u : %d v : %d\n",  u, v);
        count += 2;
        u = u - v;
    }
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
