#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

#define xfree(ptr) \
  do { \
    free(ptr); \
    ptr = NULL; \
  } while (0)

struct Pila_tag;
typedef struct Pila_tag* Pila;

Pila Crear(int size);
int Cim(Pila p);
void Apilar(Pila *ap, int elem);
void Desapilar(Pila *ap);
bool EsBuida(Pila p);
bool EsPlena(Pila p);
void Destruir(Pila *ap);
void Mostrar(Pila p);

#endif // PILA_H
