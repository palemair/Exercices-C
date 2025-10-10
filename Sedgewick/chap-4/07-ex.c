#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 7. Donnez un exemple d'arbre pour lquel la pile utilise plus de place pendant un parcours préfixé que la */
/*     file pendant un parcours par niveau. */

void visit(node nd)
{
     printf(" %c |",nd->data);
}

int main ()
{
  /* struct Node* m = nd('M',NULL,nd('N',nd('I',NULL,NULL),NULL)); */

  /* struct Node* t = nd('T',nd('E',nd('O',m,NULL),NULL),NULL); */

  /* /1* struct Node* r = nd('R',nd('A',NULL,nd('B',NULL,NULL)),NULL); *1/ */

  /* struct Node* l = nd('R',r,t); */
  
  /* struct Node* e = nd('E',l,NULL); */



  /* struct Node* T = nd('T',NULL,nd('E',NULL,nd('O',nd('M',NULL,NULL),nd('N',nd('I',NULL,NULL),NULL)))); */
  /* struct Node* R = nd('R',nd('R',nd('A',NULL,NULL),nd('B',NULL,NULL)),NULL); */
  /* struct Node* arbre = nd('E',R,T); */

  struct Node* r = nd('R',NULL,nd('E',NULL,nd('T',NULL,nd('E',NULL,NULL))));

  struct Node* o = nd('O',nd('M',r,NULL),nd('N',NULL,NULL));

  struct Node* b = nd('B',nd('A',NULL,nd('R',NULL,NULL)),o);
  
  struct Node* i = nd('I',b,NULL);

  struct Node* pt ;

  enfiler(i);

  printf("   |");
  while(!file_vide())
  {
    print_file();
    pt =defiler();
    visit(pt);
    if(pt->L) enfiler(pt->L);
    if(pt->R) enfiler(pt->R);
  }

  printf("\n\n");

  empiler(i);

  printf("   |");
  while(!pile_vide())
  {
    print_pile();
    pt =depiler();
    visit(pt);
    if(pt->R) empiler(pt->R);
    if(pt->L) empiler(pt->L);
  }

  printf("\n");

  return (EXIT_SUCCESS);
}


 /* Resultats : 

   | File : I -
 I | File : B -
 B | File : O -A -
 A | File : R -O -
 O | File : N -M -R -
 R | File : N -M -
 M | File : R -N -
 N | File : R -
 R | File : E -
 E | File : T -
 T | File : E -
 E |

   | Pile : I -
 I | Pile : B -
 B | Pile : O -A -
 A | Pile : O -R -
 R | Pile : O -
 O | Pile : N -M -
 M | Pile : N -R -
 R | Pile : N -E -
 E | Pile : N -T -
 T | Pile : N -E -
 E | Pile : N -
 N |
*/
