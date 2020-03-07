#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LeerFichero(const char *fileName, char **s);
void Operar(Pila p, char *s);
int EsNumero(char *s);

int main()
{
    char *data, *token;
    Pila pila_rpn;

    //int nElem;
    LeerFichero("input.txt", &data);
    pila_rpn = Crear(10);
    /* get the first token */
    token = strtok(data, ",");
    
    /* walk through other tokens */
    while( token != NULL ) {
        Operar(pila_rpn ,token);

        token = strtok(NULL, ",");
    }
    Mostrar(pila_rpn);
    return 0;
}

/* Function Definitions */
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

void Operar(Pila p, char *s)
{
    if (EsNumero(s))
    {
        Apilar(&p, atoi(s));
    }
    else
    {
        switch (s[0])
        {
        case '+' :
            if (Tamanio(p) < 2)
            {
                printf("Faltan numeros para sumar!\n");
                break;
            }
            else
            {
                Apilar(&p, CimDesap(&p) + CimDesap(&p));
                break;
            }

        case '-' :
            /* code */
            break;

        case '*' :
            /* code */
            break;

        case '/' :
            /* code */
            break;
        
        default:
            break;
        }
    }
    
    
}

int EsNumero(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            return 1;
        }
    }
    return 0;
}