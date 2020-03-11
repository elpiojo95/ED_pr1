/* cua.c */
#include "cua.h"
#include <stdlib.h>

struct Cua_tag
{
    int *array;
    int max;
    int index;
    int actual;
};

int Crear(Cua *ac, int size)
{
    (*ac).array = (int*) malloc(sizeof(int) * size);
    if ((*ac).array == NULL)
    {
        return ERROR_CREAR;
    }
    
    (*ac).max = size;
    (*ac).index = 0;
    (*ac).actual = 0;
    return SUCCESS;
}

int Encuar(Cua *ac, int elem)
{

}

int Desencuar(Cua*ac)
{

}

int Cap(Cuac, int*elem)
{

}

int EsBuida(Cuac, bool *b)
{

}

int EsPlena(Cuac, bool *b)
{

}

int Destruir(Cua*ac)
{

}