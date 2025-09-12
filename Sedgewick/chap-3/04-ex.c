#include <stdio.h>

int main (void)
{
    int N, M;
    char *str ="Entrez la taille du tableau et le pas du problème de joséphus : ";
    puts(str);
    scanf("%d %d",&N,&M);

    int tab[N];
    for(int u = 0; u < N;u++) tab[u] = u + 1;
    int index = M - 1;

    while(N > 1)
    {
        printf("%d ",tab[index]);
        for(int u = index; u<N;u++)
        {
            tab[u] = tab[u + 1];
        }
        N--;
        index = (index + (M-1))%N ;
    }
        printf("%d \n",tab[0]);
    return 0;
}
