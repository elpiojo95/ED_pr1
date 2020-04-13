#ifndef LLISTA_H
#define LLISTA_H

#include <stdbool.h>

#define xfree(ptr) \
  do { \
    free(ptr); \
    ptr = NULL; \
  } while (0)

struct llista_tag;
typedef struct llista_tag* llista_encadenada;

#define SUCCESS 0;
#define ERROR_MEM 1;
#define ERROR_FREE 2;
#define ERROR_FIN 3;
#define ERROR_NOEXISTE 4;
#define ERROR_VACIA 5;

int Crear(llista_encadenada *ll);
int Destruir(llista_encadenada *ll);
int Principi(llista_encadenada *ll);
int Final(llista_encadenada *ll);
int Avancar(llista_encadenada *ll);
int Retrocedir(llista_encadenada *ll);
int Es_Final(llista_encadenada ll, bool *esfinal);
int Es_Primero(llista_encadenada ll, bool *esprincipio);
int Actual(llista_encadenada ll, int *elem);
int Inserir(llista_encadenada *ll, int elem);
int Esborrar(llista_encadenada *ll);
int Longitud(llista_encadenada ll, int *lon);
int Buscar(llista_encadenada ll, int elem, bool *trobat);
int Cost_Buscar(llista_encadenada ll, int elem, int *cost);
void Mostar(llista_encadenada ll);

#endif // LLISTA_H