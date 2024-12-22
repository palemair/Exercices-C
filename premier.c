#include <stdio.h>
#include <stdlib.h>
#include "xtools.h"

typedef struct Fraction
{
    int denom;
    int num;

} fraction;

/* PGCD recursive */
int pgcdr(int u, int v)
{
  if(u<v) 
  {
      int temp = u;
      u = v;
      v = temp;
  }
  int r = u%v;

  if(r==0) return v;
  else return (pgcdr(v,r));
}

/* PGCD % */
int pgcd1(int u, int v)
{
  if(u<v) 
  {
      int temp = u;
      u = v;
      v = temp;
  }
  int r = 1;
  
  while(r>0)
  {
      r=u%v;
      u=v;
      v=r;
  }
  return u;
}

fraction* reduce(fraction *fr)
{
    int pg = pgcdr(fr->denom,fr->num);
    fr->denom /= pg;
    fr->num /= pg;
    printf("%d/%d \n",fr->denom,fr->num); 
    return fr;
}

/* PGCD SEDGEWICK */
int pgcd2(int u, int v)
{
  int t;
  while(u>0)
  {
    if (u<v)
    {
        t = u;
        u = v;
        v = t;
    }
  u = u - v;
  }
  return v;
}

int main(void) {
  
    int x,y;
    x = 461952;
    y = 116298;

    START;
    printf("%d\n",pgcdr(x,y));
    STOP;
    TPS("pgcd");

  return 0;
}
