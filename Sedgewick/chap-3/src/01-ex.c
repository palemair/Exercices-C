#include <stdio.h>

/* PGCD % */
int pgcd (int u, int v)
{
    int r;

    if (u < v)
    {
        int temp = u;

        u = v;
        v = temp;
    }

    while ((r = u % v) > 0)
    {
        u = v;
        v = r;
    }
    return v;
}

int main (void)
{
    unsigned int n;
    const unsigned MAX = 50;
    char *question = "Entrez la taille de la matrice : ";
    char buffer[MAX];
    puts(question);
    fgets(buffer,(MAX-1),stdin);
    sscanf(buffer,"%u",&n);
    
    for(unsigned int i=1;i<=n;i++)
    {
        for(unsigned int j = 1; j <=n; j++)
        {
            putchar((pgcd(i,j) == 1)? '1':'0');
            putchar(' ');
        }
    putchar('\n');
    }
   
    return 0;
}
