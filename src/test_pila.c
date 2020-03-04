#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

void estadopila(Pila p)
{
    if (EsBuida(p)) printf("La pila esta VACIA\n");
    if (EsPlena(p)) printf("La pila esta LLENA\n");
}

int main()
{
    printf("INICIO DE TEST DE PRUEBAS\n\n");
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
    return 0;

    // TO-DO hacer test con fallos para 
}
