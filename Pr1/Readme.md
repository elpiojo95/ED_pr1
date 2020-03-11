# Detalles de implementación 

`gcc   `

### Pila
Para la implementacion de la pila he decidido declarar el tipo "Pila" en el fichero "pila.h" y definiar la estructura en "pila.c", de esta manera desde un programa que utilice nuestra pila no tendra acceso a los datos de la estructura, simulando los atributos privados en las clases.
Ademas el tipo pila esta definido como puntero a una estructura, de esta manera el paso por valor es mas eficiente. He utilizado una macro para sustituir la llamda a "free" de esta manera el puntero que se libera queda igual a NULL para poder saber si ese puntero fue destruido o no.
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
La implementacion de la calculadora rpn se basa en cargar todo el fichero en un Char array y obtener tokens delimitados con ',' una limitacion que tiene es que los operadores tienen que ser de un unico caracter, de tal manera que si lee un caracter que no es [0-9] ni un operador valido se considera "chs" es decir cambio de signo


## Funciones extra

En la calculadora que implementado los siguientes operadores extra:
> Potenciación
>
> Facorial

comando de compilado
