/* pila.c */
#include "pila.h"
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
    if (size<0)
    {
        printf("Error: SIZE can't be negative!\n");
        exit(EXIT_FAILURE);
    }

    p = (struct Pila_tag*) malloc(sizeof(struct Pila_tag));
    if (p == NULL)
    {
        printf("Error: Not enough space\n");
        exit(EXIT_FAILURE);
    }
    
    p->array = (int*) malloc(sizeof(int)*size);
    if (p->array == NULL)
    {
        printf("Error: Not enough space\n");
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
        exit(EXIT_FAILURE);
    }
    return p->array[p->top];
}

void Apilar(Pila *ap, int elem)
{
    if ((*ap) == NULL)
    {
        printf("Error: Stack does not exist!\n");
        exit(EXIT_FAILURE);
    }
    
    if (EsPlena(*ap))
    {
        printf("Error: Stack is full!\n");
        exit(EXIT_FAILURE);
    }
    (*ap)->array[++(*ap)->top] = elem;
}

void Desapilar(Pila *ap)
{
    if ((*ap) == NULL)
    {
        printf("Error: Stack does not exist!\n");
    }

    if (EsBuida(*ap))
    {
        printf("Error: Stack is empty!\n");
        exit(EXIT_FAILURE);
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
        xfree((*ap)->array);
        xfree(*(ap));
        (*ap) = NULL;
    }
    else
    {
        printf("Error: Stack does not exist!\n");
        exit(EXIT_FAILURE);
    }  
}

void Mostrar(Pila p) 
{
    if (p == NULL)
    {
        printf("Error: Stack does not exist!\n");
    }
    else
    {
        printf("Pos:\tNumero:\n");
        for (int i = p->top; i >= 0; i--)
        {
            printf("%d\t%d\n", i+1, p->array[i]);
        }
    }
}

int Tamanio(Pila p)
{
    return p->top+1;
}

int CimDesap(Pila *p)
{
    int c = Cim(*p);
    Desapilar(p);
    return c;
}