#include <stdio.h>
#include "cua.h"

int main(int argc, char *argv[]) {
	Cua c = NULL, c_nocreada = NULL;
	int error = 0, num;
	bool b;

	/* Test 1 */
	error = Crear(&c, 1);
	if (error == SUCCESS) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 1\n");

	/* Test 2 */
	error = Crear(&c, -1);
	if (error == ERROR_CREAR) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 2\n");

	/* Test 3 */
	error = Crear(&c, 1);
	error = EsBuida(c_nocreada, &b);
	if (error == CUA_NO_CREADA) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 3\n");
	
	/* Test 4 */
	error = EsBuida(c, &b);
	if (b == true) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 4\n");

	/* Test 5 */
	error = Encuar(&c, 1);
	error = EsBuida(c, &b);
	if (b == false) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 5\n");

	/* Test 6 */
	error = Crear(&c, 1);
	error = EsPlena(c_nocreada, &b);
	if (error == CUA_NO_CREADA) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 6\n");
	
	/* Test 7 */
	error = EsPlena(c, &b);
	if (b == false) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 7\n");

	/* Test 8 */
	error = Encuar(&c, 1);
	error = EsPlena(c, &b);
	if (b == true) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 8\n");
	error = Destruir(&c);
	
	/* Test 9 */
	error = Crear(&c, 1);
	error = Encuar(&c, 1);
	if (error == SUCCESS) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 9\n");

	/* Test 10 */
	error = Encuar(&c, 1);
	if (error == CUA_PLENA) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 10\n");

	/* Test 11 */
	error = Desencuar(&c);
	if (error == SUCCESS) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 11\n");

	/* Test 12 */
	error = Desencuar(&c);
	if (error == CUA_BUIDA) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 12\n");

	/* Test 13 */
	error = Encuar(&c, 22);
	error = Cap(c, &num);
	if ((error == SUCCESS) && (num = 22)) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 13\n");

	/* Test 14 */
	error = Desencuar(&c);
	error = Cap(c, &num);
	if ((error == CUA_BUIDA)) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 14\n");

	/* Test 15 */
	error = Destruir(&c);
	if (error == SUCCESS) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 15\n");

	/* Test 16 */
	error = Destruir(&c);
	if (error == ERROR_DESTRUIR) printf("[ok]");
	else printf("[  ]");
	printf(" Test Crear 16\n");
	//mostrar

	return(0);
}