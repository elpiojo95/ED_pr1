#ifndef CUA_H
#define CUA_H

#include <stdbool.h>

#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define CUA_NO_CREADA 3
#define CUA_BUIDA 4
#define CUA_PLENA 5

#define xfree(ptr) \
  do { \
    free(ptr); \
    ptr = NULL; \
  } while (0)

struct Cua_tag;
typedef struct Cua_tag* Cua;

int Crear(Cua *ac, int size);
int Encuar(Cua *ac, int elem);
int Desencuar(Cua*ac);
int Cap(Cuac, int*elem);
int EsBuida(Cuac, bool *b);
int EsPlena(Cuac, bool *b);
int Destruir(Cua*ac);

#endif // CUA_H