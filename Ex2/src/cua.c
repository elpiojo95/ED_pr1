/* cua.c */
#include "cua.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Cua_tag
{
    int *array;
    int m_Elem;
    int index;
    int n_Elem;
};

int Crear(Cua *ac, int size)
{
    (*ac)->array = (int*) malloc(sizeof(int) * size);
    if ((*ac)->array == NULL)
    {
        return ERROR_CREAR;
    }
    if (size < 0)
    {
        return ERROR_CREAR;
    }
    
    (*ac)->m_Elem = size;
    (*ac)->index = 0;
    (*ac)->n_Elem = 0;

    return SUCCESS;
}

int Encuar(Cua *ac, int elem)
{
    bool estado = false;
    int err = 0;
    
    if ((*ac) == NULL)
    {
        return CUA_NO_CREADA;
    }

    if ((err = EsPlena(*ac, &estado)))
    {
        return err;
    }

    if (estado)
    {
        return CUA_PLENA;
    }

    (*ac)->array[((*ac)->index + (*ac)->n_Elem) % (*ac)->m_Elem] = elem;
    (*ac)->n_Elem++;

    return SUCCESS;
}

int Desencuar(Cua*ac)
{
    bool estado;
    int err;

    if ((*ac) == NULL)
    {
        return CUA_NO_CREADA;
    }

    if ((err = EsBuida(*ac, &estado)))
    {
        return err;
    }

    if (estado)
    {
        return CUA_BUIDA;
    }

    (*ac)->index = (*ac)->index + 1 % (*ac)->m_Elem;
    (*ac)->n_Elem--;

    return SUCCESS;
}

int Cap(Cua c, int*elem)
{
    int err = 0;
    bool estado;

    if (c == NULL)
    {
        return CUA_NO_CREADA;
    }

    if ((err = EsBuida(c, &estado)))
    {
        return err;
    }

    if (estado)
    {
        return CUA_BUIDA;
    }
    (*elem) = c->array[c->index];

    return SUCCESS;
}

int EsBuida(Cua c, bool *b)
{
    if (c == NULL)
    {
        return CUA_NO_CREADA;
    }
    
    if (c->n_Elem <= 0)
    {
        (*b) = true;
    }
    else
    {
        (*b) = false;
    }
    return SUCCESS;
}

int EsPlena(Cua c, bool *b)
{
    if (c == NULL)
    {
        return CUA_NO_CREADA;
    }
    
    if (c->n_Elem >= c->m_Elem)
    {
        (*b) = true;
    }
    else
    {
        (*b) = false;
    }
    return SUCCESS;
}

int Destruir(Cua *ac)
{
    return SUCCESS;
}

int Mostrar(Cua c)
{
    if (c == NULL)
    {
        return CUA_NO_CREADA;
    }

    for (int i = 0; i < c->n_Elem; i++)
    {
        printf("%i ", c->array[(c->index + i) % c->m_Elem]);
    }
    printf("\n");

    return SUCCESS;
}