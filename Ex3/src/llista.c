#include "llista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node_tag Node;

struct Node_tag
{
    int data;
    Node *siguiente;
    Node * anterior;
};

struct llista_tag
{
    Node *primero;
    Node *ultimo;
    Node *pdi;
};

Node* CrearNode(int num);

/* TESTED */
int Crear(llista_encadenada *ll)
{
    if (ll == NULL)
    {
        return ERROR_NOEXISTE;
    }

    llista_encadenada l_temp;
    l_temp = (struct llista_tag*) malloc(sizeof(struct llista_tag));
    if (l_temp == NULL)
    {
        return ERROR_MEM;
    }

    Node *n_temp = CrearNode(9057);

    l_temp->ultimo = n_temp;
    l_temp->primero = n_temp;
    l_temp->pdi = n_temp;

    (*ll) = l_temp;
    return SUCCESS;
}

/* TESTED */
int Destruir(llista_encadenada *ll)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }

    int dim;
    Longitud((*ll), &dim);
    Principi(ll);
    for (int  i = 0; i < dim; i++)
    {
        Esborrar(ll);
    }
    xfree((*ll)->pdi);
    xfree((*ll));
    return SUCCESS;
}

/* TESTED */
int Principi(llista_encadenada *ll)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }

    (*ll)->pdi = (*ll)->primero;
    return SUCCESS;
}

/* TESTED */
int Final(llista_encadenada *ll)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }

    (*ll)->pdi = (*ll)->ultimo;
    return SUCCESS;
}

/* TESTED */
int Avancar(llista_encadenada *ll)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }

    bool estado;
    Es_Final((*ll), &estado);
    if (!estado)
    {
        (*ll)->pdi = (*ll)->pdi->siguiente;
        return SUCCESS;
    }
    return ERROR_FIN;
}

/* TESTED */
int Retrocedir(llista_encadenada *ll)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }

    if ((*ll)->pdi->anterior != NULL)
    {
        (*ll)->pdi = (*ll)->pdi->anterior;
        return SUCCESS;
    }
    return ERROR_FIN;
}

/* TESTED */
int Es_Final(llista_encadenada ll, bool *esfinal)
{
    if (ll == NULL)
    {
        return ERROR_NOEXISTE;
    }
    
    if (ll->pdi->siguiente == NULL)
    {
        (*esfinal) = true;
        return SUCCESS;
    }
    else
    {
        (*esfinal) = false;
        return SUCCESS;
    }
}

/* TESTED */
int Actual(llista_encadenada ll, int *elem)
{
    if (ll == NULL)
    {
        return ERROR_NOEXISTE;
    }

    if (ll->pdi == NULL)
    {
        return ERROR_VACIA;
    }
    else
    {
        (*elem) = ll->pdi->data;
        return SUCCESS;
    }
}

/* TESTED */
int Inserir(llista_encadenada *ll, int elem)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }

    Node* newNode = CrearNode(elem);
	if(newNode == NULL) 
    {
		return ERROR_MEM;
	}
    newNode->anterior = (*ll)->pdi->anterior;
	newNode->siguiente = (*ll)->pdi;

    if ((*ll)->primero == (*ll)->pdi)
    {
        (*ll)->primero = newNode;
    }
    else
    {
        (*ll)->pdi->anterior->siguiente = newNode;
    }
	(*ll)->pdi->anterior = newNode;
    
    return SUCCESS;
}

/* TESTED */
int Esborrar(llista_encadenada*ll)
{
    if ((*ll) == NULL)
    {
        return ERROR_NOEXISTE;
    }
    if ((*ll)->pdi->siguiente == NULL)
    {
        return ERROR_FIN;
    }
    Node* n;
    if ((*ll)->pdi->anterior != NULL)
    {
        (*ll)->pdi->anterior->siguiente = (*ll)->pdi->siguiente;
    }
    else
    {
        (*ll)->primero = (*ll)->pdi->siguiente;
    }
    
    (*ll)->pdi->siguiente->anterior = (*ll)->pdi->anterior;
    n = (*ll)->pdi->siguiente;
    xfree((*ll)->pdi);
    (*ll)->pdi = n;
    return SUCCESS;
}

/* TESTED */
int Longitud(llista_encadenada ll, int *lon)
{
    if (ll == NULL)
    {
        return ERROR_NOEXISTE;
    }
    Node *nd;
    nd = ll->primero;
    (*lon) = 0;
    while (nd->siguiente != NULL)
    {
        (*lon)++;
        nd = nd->siguiente;
    }
    return SUCCESS;
}

/* TESTED */
int Buscar(llista_encadenada ll, int elem, bool *trobat)
{
    if (ll == NULL)
    {
        return ERROR_NOEXISTE;
    }
    Node *nd;
    nd = ll->primero;
    while (nd->siguiente != NULL)
    {
        if (nd->data == elem)
        {
            (*trobat) = true;
            return SUCCESS;
        }
        nd = nd->siguiente;
    }
    (*trobat) = false;
    return ERROR_NOEXISTE;
}

/* TESTED */
int Cost_Buscar(llista_encadenada ll, int elem, int *cost)
{
    if (ll == NULL)
    {
        return ERROR_NOEXISTE;
    }
    Node *nd;
    nd = ll->primero;
    (*cost) = 0;
    while (nd->siguiente != NULL)
    {
        (*cost)++;
        if (nd->data == elem)
        {
            return SUCCESS;
        }
        nd = nd->siguiente;
    }
    return ERROR_NOEXISTE;
}

/* TESTED */
Node* CrearNode(int num)
{
    Node *n_temp ;
    n_temp = (struct Node_tag*) malloc(sizeof(struct Node_tag));
    if (n_temp == NULL)
    {
        return NULL;
    }
    n_temp->data = num;
    n_temp->siguiente = NULL;
    n_temp->anterior = NULL;
    return n_temp;
}

/* TESTED */
void Mostar(llista_encadenada ll)
{
    Node *nd;
    nd = ll->primero;
    while (nd != NULL)
    {
        printf("\n----------%p----------\n",nd);
        printf("\tAnt:%p\t\n", nd->anterior);
        printf("\tDat:%d\n", nd->data);
        printf("\tSig:%p\n", nd->siguiente);
        printf("----------------------------------\n");
        nd = nd->siguiente;
    }
}