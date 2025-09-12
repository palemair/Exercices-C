#include <stdio.h>
#include <stdlib.h>

#define max 100

static int cle[max + 2], suivant[max + 2];

static int x, debut, z;

void initialise(void)
{
    x = 2;
    debut = 0;
    z = 1;
    suivant[debut] = z;
    suivant[z] = z;
}

void print_list (void)
{
    int u = suivant[debut];
    while(suivant[u] != u)
    {
        printf("%2c > ",cle[u]);
        u = suivant[u];
    }
    puts("EOL");
}

void print (void)
{
    int u = 0;
    while(u< x )
    {
        printf("%2c | ",cle[u++]);
    }
    puts("EOT");
}

void suppsuivant (int t)
{
    suivant[t] = suivant[suivant[t]];
}

int inserapres(int v,int t)
{
    cle[x] = v;
    suivant[x] = suivant[t];
    suivant[t] = x;
    return x++;
}

int main(void)
{
    initialise();
    int c,d;

    d = inserapres('T',debut);
    c = inserapres('I',debut);
    inserapres('L',debut);
    
    inserapres('S',c);
    inserapres('E',d);
    print_list();
    print();

    return 0;
}
