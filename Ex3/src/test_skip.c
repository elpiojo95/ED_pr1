#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include "skip.h"
#include "random.h"

float CalcularSd(int data[],float media);
float CalcularMedia(int data[]);

int main(int argc, char *argv[]) {
    int n, r, cost, test, err, data[1000];
    long seed1, seed2;
    float media, sd;
    bool b;
    FILE *fptr;
    fptr = fopen("data_skip.csv","w");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    srand(time(0));
    phrtsd("patata", &seed1, &seed2);
    setall(seed1, seed2);

    for (test = 1; test <= 50; test++) {
        printf("---Comienzo Test %d---\n",test);
        
        skip_list l;
        err = Crear(&l);
        if (err)
        {
            printf("error: %d\n", err);
        }
        
        n = test * 1000;
        for (int i = 0; i < n; i++)
        {
            r = ignuin(1, n*2);
            Inserir(&l, r);
        }
        for (int i = 0; i < 1000; i++)
        {
            r = ignuin(1, n*2);
            Cost_Buscar(l, r, &cost);
            Buscar(l,r,&b);
            data[i] = cost;
        }
        media = CalcularMedia(data);
        sd = CalcularSd(data, media);
        fprintf(fptr,"%d;%f;%f\n",n, media, sd);
        printf("test:%d media:%0.2f desv:%f\n",n, media, sd);
        err = Destruir(&l);
        if (err)
        {
            printf("error_Destru: %d\n", err);
        }
        
        printf("---Fin Test %d---\n\n",test);
    }
    fclose(fptr);

    return(0);
}

float CalcularMedia(int data[])
{
    int acum=0;
    for (int i = 0; i < 1000; i++)
    {
        acum +=data[i];
    }
    return acum/(float)1000;
}

float CalcularSd(int data[],float media)
{
    float sd=0.0;
    for (int i = 0; i < 1000; i++)
        sd += pow(data[i] - media, 2);
    return sqrt(sd / 1000);
}
