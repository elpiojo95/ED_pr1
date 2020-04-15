#ifndef SKIP_H
#define SKIP_H

#include <stdbool.h>

#define xfree(ptr) \
  do { \
    free(ptr); \
    ptr = NULL; \
  } while (0)

struct skip_list_tag;
typedef struct skip_list_tag* skip_list;

#define SUCCESS 0;
#define ERROR_MEM 1;
#define ERROR_FREE 2;
#define ERROR_FIN 3;
#define ERROR_NOEXISTE 4;
#define ERROR_VACIA 5;
#define NO_TROBAT 6;

int Crear(skip_list*sl);
int Destruir(skip_list *sl);
int Inserir(skip_list *sl, int elem);
int Esborrar(skip_list *sl, int elem);
int Longitud(skip_list sl, int *lon);
int Buscar(skip_list sl, int elem, bool *trobat);
int Cost_Buscar(skip_list sl, int elem, int *cost);



#endif // SKIP_H