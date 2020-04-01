# Detalles de implementación 
`gcc -Wall -g -o test_cua cua.h  cua.c test_cua.c`

`gcc -Wall -g -o triangulo cua.h  cua.c trianglePascal.c`

### Cua
Para la implementación de la cola me he basado en la implementacion base de la pila. 

### Juego de pruebas
El programa test_cua es una bateria de pruebas que comprueba que se obtiene el resultado correcto.

### Triangulo
Para la implementación del triangulo de pascal he utilizado una unica cola para ir guardando los valores calculados y asi utilizarlos en la siguiente fila

## Funciones extra

En la cola he implementado las siguientes funciones extra:
> EncuarPlus
 
Encola y en caso de falta de espacio lo aumenta
