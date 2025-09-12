#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char value;
    struct Node *nxt;
};

static struct Node *tete, *queue, *z, *tmp;

void init_file(void)
{
    tete = z;
    queue = z;
}

int file_vide(void)
{
    return tete == z;
}

void enfiler(char v)
{
    struct Node *new = malloc(sizeof(*new));
    new->value = v;
    new->nxt = z;

    if(file_vide())
    {
        tete = new;
        queue = new;
    }
    else
    {
        queue->nxt = new;
        queue = new;
    }
}

int defiler(void)
{
    if(!file_vide())
    {
        tmp = tete;
        int ret = tmp->value;

        tete = tete->nxt;
        free(tmp);
        return ret;
    }
    else 
    {
        printf("file vide\n");
        return '|';
    }
}

void print_file(struct Node* pt)
{
    if(pt ==z)
    {
       printf("Queue ");
       return;
    }
       
    else
    {
       print_file(pt->nxt);
       printf("-> %c ",pt->value);
    }
}

int main(void)
{
    init_file();
    for(int u = 65;u<75;u++) enfiler(u);
    print_file(tete);
    putchar('\n');

    printf("defiler %c <- ",defiler());
    putchar('\n');

    printf("enfiler -> %c \n",77);
    enfiler(77);
    printf("enfiler -> %c \n",80);
    enfiler(80);

    printf("defiler %c <- ",defiler());
    printf("%c <- ",defiler());
    printf("%c <- ",defiler());
    putchar('\n');
    print_file(tete);
    putchar('\n');
}
