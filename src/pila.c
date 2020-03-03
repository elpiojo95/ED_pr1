/* pila.c */
#include "pila.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    if (p == NULL)
    {
        errnum = errno;
        printf("Error: %s\n", strerror(errnum));
        exit(EXIT_FAILURE);
    }
    
    p->array = (int*) malloc(sizeof(int)*size);
    if (p->array == NULL)
    {
        errnum = errno;
        printf("Error: %s\n", strerror(errnum));
        exit(EXIT_FAILURE);
    }

    p->max = size;
    p->top = -1;
    return p;
}

int Cim(Pila p)
{
    if (EsBuida(p))
    {
        // return some error
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return p->array[p->top];
}

void Apilar(Pila *ap, int elem)
{
    if (EsPlena(*ap))
    {
        printf("Error: Stack is full!\n");
        exit(1);
    }
    (*ap)->array[++(*ap)->top] = elem;
}

void Desapilar(Pila *ap)
{
    if (EsBuida(*ap))
    {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    (*ap)->top--;
}

bool EsBuida(Pila p)
{
    if (p->top <= -1)
    {
        return true;
    }
    return false;
}

bool EsPlena(Pila p)
{
    if (p->top >= p->max - 1)
    {
        return true;
    }
    return false;
}

void Destruir(Pila *ap)
{
    if ((*ap) != NULL)
    {
        free((*ap)->array);
        free(*ap);
    }
    else
    {
        // return some error
        printf("Error: Stack does not exist!\n");
        exit(1);
    }  
}

void Mostrar(Pila p) 
{
    /*if (EsBuida(p))
    {
        printf("Error: Stack is empty!\n");
        exit(1);
    }*/
    printf("Pos:\tNumero:\n");
    for (int i = p->top; i >= 0; i--)
    {
        printf("%d\t%d\n", i+1, p->array[i]);
    }
}
