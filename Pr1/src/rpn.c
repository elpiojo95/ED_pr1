#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LeerFichero(const char *fileName, char **s);
void Operar(Pila p, char *s);
int EsNumero(char *s);
int Pot(int base, int exp);
int Fact(int n);

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
                printf("\nFaltan numeros para sumar!\n");
                exit(EXIT_FAILURE);
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
                printf("\nFaltan numeros para restar!\n");
                exit(EXIT_FAILURE);
                break;
            }
            else
            {
                int op1 = CimDesap(&p);
                Apilar(&p, CimDesap(&p) - op1);
                break;
            }
            break;

        case '*' :
            if (Tamanio(p) < 2)
            {
                printf("\nFaltan numeros para multiplicar!\n");
                exit(EXIT_FAILURE);
                break;
            }
            else
            {
                Apilar(&p, CimDesap(&p) * CimDesap(&p));
                break;
            }
            break;

        case '/' :
            if (Tamanio(p) < 2)
            {
                printf("\nFaltan numeros para multiplicar!\n");
                exit(EXIT_FAILURE);
                break;
            }
            else
            {
                int op1 = CimDesap(&p);
                int op2 = CimDesap(&p);
                if (op2 == 0)
                {
                    printf("\nNo se puede dividir por 0 :(\n");
                    exit(EXIT_FAILURE);
                }
                Apilar(&p, op2 / op1);
                break;
            }

        case '^' :
            if (Tamanio(p) < 2)
            {
                printf("\nFaltan numeros para operar!\n");
                exit(EXIT_FAILURE);
                break;
            }
            else
            {
                int op1 = CimDesap(&p);
                int op2 = CimDesap(&p);
                Apilar(&p, Pot(op2, op1));
                break;
            }

        case '!' :
            if (Tamanio(p) < 1)
            {
                printf("\nLa pila no tiene numeros!\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                Apilar(&p, Fact(CimDesap(&p)));
                break;
            }
            
        default:
            if (Tamanio(p) < 1)
            {
                printf("\nFaltan numeros para operar!\n");
                exit(EXIT_FAILURE);
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

int Pot(int base, int exp)
{
    int result = 1;
    while (exp != 0)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

int Fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * Fact(n-1);
    }
    
    
}