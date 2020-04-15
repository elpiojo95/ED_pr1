#include <stdlib.h>
#include <stdio.h>
#include "skip.h"
#include <stdbool.h>
#include <limits.h>

#define SKIPLIST_MAX_LEVEL 15
typedef struct Node_tag node;

struct Node_tag {
    int valor;
    int level;
    node **next;
};

struct skip_list_tag {
    int longitud;
    node *header;
};

int RandomLevel(int max);
node* CrearNode(int val, int level);

// TESTED //
int Crear(skip_list *sl)
{
    /*if ((*sl == NULL)
    {
        return ERROR_NOEXISTE;
    }*/

    skip_list sl_temp;
    sl_temp = (struct skip_list_tag*) malloc(sizeof(struct skip_list_tag));
    if (sl_temp == NULL)
    {
        return ERROR_MEM;
    }
    node *n = CrearNode(INT_MIN, SKIPLIST_MAX_LEVEL);
    for (int i = 0; i < SKIPLIST_MAX_LEVEL; i++)
    {
        n->next[i] = NULL;
    }
    
    sl_temp->longitud = 0;
    sl_temp->header = n;
    (*sl) = sl_temp;
    return SUCCESS;
}

// TESTED //
node* CrearNode(int val, int level)
{
    node *n_temp ;
    n_temp = malloc(sizeof(struct Node_tag));
    if (n_temp == NULL)
    {
        return NULL;
    }
    n_temp->next = malloc(sizeof(node*) * (level+1));
    n_temp->valor = val;
    n_temp->level = level;
    return n_temp;
}

// TESTED //
int Destruir(skip_list *sl)
{
    if ((*sl) == NULL)
    {
        return ERROR_NOEXISTE;
    }
    node *n_temp;
    for (int i = 0; i <= (*sl)->longitud; i++)
    {
        n_temp = (*sl)->header;
        (*sl)->header = (*sl)->header->next[0];
        xfree(n_temp);
    }
    xfree((*sl)->header);
    xfree((*sl));
    return SUCCESS;
}

// TESTED //
int Inserir(skip_list *sl, int elem)
{
    if ((*sl) == NULL)
    {
        return ERROR_NOEXISTE;
    }
    int level;
    node *new = CrearNode(elem, RandomLevel(SKIPLIST_MAX_LEVEL));
    node *n;
    n = (*sl)->header;

    /* Buscamos la posicion mas alta anterior a elem */
    for (level = (*sl)->header->level; level >= new->level; level--)
    {
        while(n->next[level] && n->next[level]->valor < elem)
        {
            n = n->next[level];
        }
    }
    level++;
    /* level esta en la altura de new */
    for (; level >= 0; level--)
    {
        while(n->next[level] && n->next[level]->valor < elem)
        {
            n = n->next[level];
        }
        new->next[level] = n->next[level];
        n->next[level] = new;
    }
    (*sl)->longitud++;
    return SUCCESS;
}

int Esborrar(skip_list *sl, int elem)
{
    return SUCCESS;
}

// TESTED //
int Longitud(skip_list sl, int *lon)
{
    (*lon) = sl->longitud;
    return SUCCESS;
}

// TESTED //
int Buscar(skip_list sl, int elem, bool *trobat)
{
    int level;
    node *n;
    n = sl->header;
    
    for(level = sl->header->level; level >= 0; level--) {
        while(n->next[level] && n->next[level]->valor <= elem) {
            if (n->next[level]->valor == elem)
            {
                (*trobat) = true;
                return SUCCESS;
            }
            n = n->next[level];
        }
    }
    (*trobat) = false;
    return SUCCESS;
}

// TESTED //
int Cost_Buscar(skip_list sl, int elem, int *cost)
{
    int level;
    (*cost) = 0;
    node *n;
    n = sl->header;

    for(level = sl->header->level; level >= 0; level--) {
        while(n->next[level] && n->next[level]->valor <= elem) {
            if (n->next[level]->valor == elem)
            {
                (*cost) ++;
                return SUCCESS;
            }
            n = n->next[level];
            (*cost) ++;
        }
        (*cost) ++;
    }
    (*cost)++;
    return SUCCESS;
}

// TESTED //
int RandomLevel(int max)
{
    int n=0;
    while(rand() & 1 && n<max-1) n++;
    return n;
}

