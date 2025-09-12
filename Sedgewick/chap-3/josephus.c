#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
};

int main (void)
    
{
    int N, M;
    struct Node *ptr, *begin;
    
    scanf("%d %d",&N,&M);

    ptr = malloc (sizeof *ptr);
    ptr->data = 1;
    begin = ptr;

    for(int u = 2; u<=N;u++)
    {
        ptr->nxt = malloc (sizeof *ptr);
        ptr = ptr -> nxt;
        ptr->data = u;
    }
    
    ptr->nxt = begin;

    while(ptr != ptr->nxt)
    {
        for(int u = 1; u<M;u++)
            ptr = ptr->nxt;
        printf("%d ",ptr->nxt->data);
        begin = ptr->nxt;
        ptr->nxt = ptr->nxt->nxt;
        free(begin);
    }

    printf("%d\n",ptr->data);
}
