#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

void TestSinFallos();
void TestFalloPilaNegativa();
void TestFalloApilarNoExiste();
void TestFalloApilarLlena();
void TestFalloDesapilarVacia();


void estadopila(Pila p)
{
    if (EsBuida(p)) printf("La pila esta VACIA\n");
    if (EsPlena(p)) printf("La pila esta LLENA\n");
}

int main(int argc, char *argv[])
{
    printf("INICIO DE TEST DE PRUEBAS\n\n");
    if (argc == 2)
    {
        switch (argv[1][0])
        {
        case '1':
            TestFalloPilaNegativa();
            break;

        case '2':
            TestFalloApilarNoExiste();
            break;

        case '3':
            TestFalloApilarLlena();
            break;

        case '4':
            TestFalloDesapilarVacia();
            break;
        
        default:
            TestSinFallos();
            break;
        }
    }
    else if (argc > 2)
    {
        printf("Too many arguments\n");
        for (int i = 0; i < 5; i++)
        {
            printf("Try: %s %d\n", argv[0], i);
        }
        
    }
    else
    {
        TestSinFallos();
    }
    return 0;
}

void TestSinFallos()
{
    int numeros[] = {2,53,127,199,283,383,467,577,661,769};

    /* CREAR PILA */
    printf("Creando pila...\n");
    Pila p = Crear(10);
    printf("Pila creada!\n");
    estadopila(p);

    /* RELLENAR PILA */
    printf("\nLlenando pila...\n");
    for (int i = 0; i < 10; i++) Apilar(&p, numeros[i]);
    printf("La pila se ha llenado!\n");
    estadopila(p);
    Mostrar(p);

    /* VER CIMA */
    printf("\nLa Cima es: %d\n", Cim(p));
    estadopila(p);

    /* DESAPILAR */
    printf("\nVaciando la pila...\n");
    for (int i = 0; i < 5; i++) Desapilar(&p);
    estadopila(p);
    Mostrar(p);
    for (int i = 0; i < 5; i++) Desapilar(&p);
    printf("Pila Vaciada!\n");
    estadopila(p);
    Mostrar(p);

    /* DESTRUIR */
    printf("\nDestruyendo la pila...\n");
    Destruir(&p);
    printf("Pila destruida!\n");
    Mostrar(p);

    /* CREAR SOBRE LA MISMA VARIABLE */
    printf("\nCreando pila en la misma variable...\n");
    p = Crear(5);
    printf("Pila creada!\n");
    estadopila(p);
    printf("Apilamos un 22!\n");
    Apilar(&p, 22);
    estadopila(p);
    Mostrar(p);
    Destruir(&p);

    /* FIN DEL TEST */
    printf("\n\tEl test ha sido un exito!\n");
}

void TestFalloPilaNegativa()
{
    printf("Creando pila...\n");
    Pila p = Crear(-1);
    printf("Pila creada!\n");
    estadopila(p);
}

void TestFalloApilarNoExiste()
{
    printf("Creando pila...\n");
    Pila p = Crear(1);
    printf("Pila creada!\n");
    estadopila(p);
    printf("Destruyendo pila...\n");
    Destruir(&p);
    printf("Pila destruida!\n");
    printf("Apilando...\n");
    Apilar(&p, 1);
    estadopila(p);
}

void TestFalloApilarLlena()
{
    printf("Creando pila...\n");
    Pila p = Crear(1);
    printf("Pila creada, dimension 1!\n");
    estadopila(p);
    printf("Apilando un numero\n");
    Apilar(&p, 1);
    estadopila(p);
    printf("Apilando otro numero\n");
    Apilar(&p, 1);
    estadopila(p);
}

void TestFalloDesapilarVacia()
{
    printf("Creando pila...\n");
    Pila p = Crear(0);
    estadopila(p);
    printf("Pila creada, dimension 0!\n");
    printf("Desapilando...\n");
    Desapilar(&p);
    estadopila(p);
}