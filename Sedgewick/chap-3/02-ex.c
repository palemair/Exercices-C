#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
};

static struct Node *ptr, *begin, *end;

void initialise(void)
{
    begin = malloc (sizeof *begin);
    end = malloc (sizeof *end);
    begin->nxt = end;
    end->nxt = end;
}

void print_list (void)
{
    ptr = begin->nxt;
    while(ptr!= end)
    {
        printf("%3c >",ptr->data);
        ptr = ptr->nxt;
    }
    puts("EOL");
}

void depsuivant (struct Node *t)
{
    struct Node* temp = t->nxt;
    t->nxt = t->nxt->nxt;
    
    temp->nxt = begin->nxt;
    begin->nxt = temp;
}

int main(void)
{

    initialise();
    struct Node *p = begin;

    for(int u = 65;u<80;u++)
    {
       struct Node *x = malloc (sizeof (*x));
       x->data = u;
       p->nxt = x;
       p =x;
    }
    p->nxt = end;

    print_list();
    
    p =begin;

    while(p != end)
    {
        if(p->nxt->data == 'E') break;
        p=p->nxt;
    }
    depsuivant(p);

    print_list();
}
