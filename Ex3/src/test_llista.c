#include <stdio.h>
#include "llista.h"

int main(int argc, char *argv[]) {
    llista_encadenada l;
    int dim, err;

    Crear(&l);
    //***Rellenar***//
    for (int i = 1; i < 2; i++)
    {
        Inserir(&l, i);
    }

    return(0);
}