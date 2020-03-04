#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("input.txt","r");
    int size;

    if (file == NULL)
    {
        printf("File does not exist!\n");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END); // seek to end of file
    size = ftell(file); // get current file pointer
    fseek(file, 0, SEEK_SET); // seek back to beginning of file
    fclose(file);
    printf("size: %d", size);
    return 0;
}
