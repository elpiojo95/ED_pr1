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
    Cua c;
    
    if (size < 0)
    {
        return ERROR_CREAR;
    }

    c = (struct Cua_tag*) malloc(sizeof(struct Cua_tag));
    if (c == NULL)
    {
        return ERROR_CREAR;
    }

    c->array = (int*) malloc(sizeof(int) * size);
    if (c->array == NULL)
    {
        return ERROR_CREAR;
    }
    
    c->m_Elem = size;
    c->index = 0;
    c->n_Elem = 0;

    (*ac) = c;
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

int EncuarPlus(Cua *ac, int elem)
{
    bool estado = false;
    int err = 0, num, max;
    Cua temp;
    
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
        if ((*ac)->m_Elem == 0)
        {
            (*ac)->m_Elem = 1;
        }
        
        err = Crear(&temp, (*ac)->m_Elem * 2);
        if (err) return ERROR_AMPLIAR;
        max = (*ac)->n_Elem;
        for (int i = 0; i < max; i++)
        {
            Cap((*ac), &num);
            Encuar(&temp, num);
            Desencuar(ac);
        }
        Destruir(ac);
        (*ac) = temp;
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

    (*ac)->index = ((*ac)->index + 1) % (*ac)->m_Elem;
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
    if ((*ac) != NULL)
    {
        xfree((*ac)->array);
        xfree(*(ac));
        return SUCCESS;
    }
    return ERROR_DESTRUIR;
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