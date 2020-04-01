#include <stdio.h>
#include "cua.h"

void printPascal(int n)
{
    
    if (n > 0)
    {
        Cua cola;
        int num1, num2, temp;
        Crear(&cola, 0);
        printf("1\n");

        for (int line = 1; line < n; line++)
        {
            int col = 0;
            printf("1 ");
            EncuarPlus(&cola, 1);
            col++;

            if (col < line)
            {
                Cap(cola, &num1);
                Desencuar(&cola);
                Cap(cola, &num2);
                Desencuar(&cola);
                temp = num1 + num2;
                printf("%d ",temp);
                EncuarPlus(&cola, temp);
                col++;
                while (col < line)
                {
                    Cap(cola, &num1);
                    Desencuar(&cola);
                    temp = num1 + num2;
                    printf("%d ", temp);
                    EncuarPlus(&cola, temp);
                    num2 = num1;
                    col++;
                }
            }
            printf("1\t");
            EncuarPlus(&cola, 1);
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("Piramide de %d:\n", i);
        printPascal(i);
    }
    return 0;
}
