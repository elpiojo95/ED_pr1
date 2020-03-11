# Detalles de implementación 
`gcc -Wall -g -o test_pila pila.h  pila.c test_pila.c`

`gcc -Wall -g -o rpn pila.h  pila.c rpn.c`

### Pila
Para la implementación de la pila he decidido declarar el tipo "Pila" en el fichero "pila.h" y definir la estructura en "pila.c", de esta manera desde un programa que utilice nuestra pila no tendrá acceso a los datos de la estructura, simulando los atributos privados en las clases.
Además el tipo pila esta definido como puntero a una estructura, de esta manera el paso por valor es más eficiente. He utilizado una macro para sustituir la llamada a "free" de esta manera el puntero que se libera queda igual a NULL para poder saber si ese puntero fue destruido o no.
### Juego de pruebas
El programa test_pila es un lanzador de juegos de prueba. Al ejecutar podemos elegir que prueba lanzar

>TestSinFallos:
>`test_pila`

>TestFalloPilaNegativa:
`test_pila 1`

>TestFalloApilarNoExiste:
`test_pila 2`

>TestFalloApilarLlena:
`test_pila 3`

>TestFalloDesapilarVacia:
`test_pila 4`


### Calculadora
La implementación de la calculadora rpn se basa en cargar todo el fichero en un Char array y obtener tokens delimitados con ',' una limitación que tiene es que los operadores tienen que ser de un único carácter, de tal manera que si lee un carácter que no es [0-9] ni un operador valido se considera "chs" es decir cambio de signo


## Funciones extra

En la calculadora que implementado los siguientes operadores extra:
> Potenciación
>
> Facorial
