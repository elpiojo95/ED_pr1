#include <stdio.h>
#include "cua.h"

#define MAX 15

int main(int argc, char *argv[]) {
	Cua c;
	int error = 0, top;
	error = Crear(&c, MAX);
	if (error)
	{
		printf("EROOOOOOR crear: %d \n", error);
	}
	for (int i = 0; i < MAX; i++)
	{
		error = Encuar(&c, i+1);
		if (error)
		{
			printf("Error Encuar: %d\n", error);
		}
	}
	Mostrar(c);
	error = Cap(c, &top);
	if (error)
	{
		printf("Error Cap: %d\n", error);
	}
	printf("%d\n", top);

	error = Desencuar(&c);
	error = Desencuar(&c);
	error = Desencuar(&c);
	error = Desencuar(&c);
	error = Desencuar(&c);
	error = Desencuar(&c);
	error = Encuar(&c, 22);
	if (error)
	{
		printf("Error Desencuar: %d\n", error);
	}
	error = Cap(c, &top);
	if (error)
	{
		printf("Error Cap: %d\n", error);
	}

	printf("%d\n", top);
	Mostrar(c);
	
	return(0);
}