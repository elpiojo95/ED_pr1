#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

struct Pila_tag;
typedef struct Pila_tag* Pila;

int errnum;

Pila Crear(int size);
int Cim(Pila p);
void Apilar(Pila *ap, int elem);
void Desapilar(Pila *ap);
bool EsBuida(Pila p);
bool EsPlena(Pila p);
void Destruir(Pila *ap);
void Mostrar(Pila p);

#endif // PILA_H
