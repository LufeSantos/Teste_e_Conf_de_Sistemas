// Autor: Luís Fernando Becker Santos
// Email: luis.s@edu.pucrs.br

#include "sort.h"

static void swap(int* v1, int* v2)
{
  int aux = *v1;
  *v1 = *v2;
  *v2 = aux;
}

void sort (int *v, int size)
{
  for(int i=0; i<size; i++)
    for(int j=0; j<size-1; j++)
      if(v[j]>v[j+1]){
        swap(v+j,v+j+1);
      }
}
