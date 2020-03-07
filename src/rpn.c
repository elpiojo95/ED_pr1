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
        printf("%s ", token);
        token = strtok(NULL, ",");
    }
    printf("\nResultado [%d]\n", Cim(pila_rpn));
    if (Tamanio(pila_rpn) == 1)
    {
        printf("Resultado Correcto!!!\n");
    }
    else
    {
        printf("Algo a fallado al operar!!!\n");
    }
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
            if (Tamanio(p) < 2)
            {
                printf("Faltan numeros para restar!\n");
                break;
            }
            else
            {
                int op1 = CimDesap(&p);
                int op2 = CimDesap(&p);
                Apilar(&p, op2 - op1);
                break;
            }
            break;

        case '*' :
            if (Tamanio(p) < 2)
            {
                printf("Faltan numeros para multiplicar!\n");
                break;
            }
            else
            {
                Apilar(&p, CimDesap(&p) * CimDesap(&p));
                break;
            }
            break;

        case '/' :
            /* code */
            break;
        
        default:
            if (Tamanio(p) < 1)
            {
                printf("Faltan numeros para operar!\n");
                break;
            }
            else
            {
                Apilar(&p, CimDesap(&p) * -1);
                break;
            }
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