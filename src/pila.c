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
    p = malloc(sizeof(struct Pila_tag));
    p->max = size;
    return p;
}