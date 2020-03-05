#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LeerFichero(const char *fileName, char **s);

int main()
{
    char *data;
    int nElem;
    nElem = LeerFichero("input.txt", &data);
    printf("size: %d, string: %s", nElem, data);

    return 0;
}


int LeerFichero(const char *fileName, char **s)
{
    FILE *file = fopen(fileName,"r");
    int size;

    if (file == NULL)
    {
        printf("File does not exist!\n");
        exit(EXIT_FAILURE);
    }
    /* Get string size from file */
    fseek(file, 0, SEEK_END);
    size = ftell(file) + 1; // un tamaño extra para la coma final
    fseek(file, 0, SEEK_SET);

    /* Allocate memory plus 1 for extra char*/
    *s = (char*) malloc(sizeof(char)*size);
    if (s == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Full the string with file data */
    int i;
    for (i = 0; i < size-1; i++) // todo menos la ultima posicion que es coma
    {
        (*s)[i] = fgetc(file);
    }
    (*s)[i] = ',';
    fclose(file);
    return size;
}