/* pila.c */
#include "pila.h"
#include <stdlib.h>

struct Pila_tag
{
    int max;
    int top;
    int *array;
};

Pila Crear(int size)
{
    Pila p;
    p = (struct Pila_tag*) malloc(sizeof(struct Pila_tag));
    p->max = size;
    p->array = (int*) malloc(sizeof(int)*size);
    p->top = -1;
    return p;
}

