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
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory & full string */
    *s = (char*) malloc(sizeof(char)*size);
    if (s == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++)
    {
        (*s)[i] = fgetc(file);
    }
    fclose(file);
    return size;
}