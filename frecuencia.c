// Ingresar 1000 edades en un vector e indicar 
// cuál es la edad de mayor frecuencia (la que más se repite).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10


void mostrar(int * matriz, int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("%i ", matriz[i]);
    }
    printf("\n");
}

int frecuencia(int * matriz, int cantidad){
    int vector_auxiliar[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        vector_auxiliar[i] = 0;
    }
    mostrar(vector_auxiliar, cantidad);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        int actual = matriz[i];
        vector_auxiliar[actual]++;
    }

    int mayor = -1;
    int mayor_prosicion = -1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (vector_auxiliar[i] > mayor)
        {
            mayor = vector_auxiliar[i];
            mayor_prosicion = i;
        }
    }
    return mayor_prosicion;
}

int main()
{
    srand(time(NULL));

    int vector1[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    { 
        vector1[i] = rand() % 10;
    }

    mostrar(vector1, MAX_SIZE);    
    
    int elemento_que_mas_se_repite = frecuencia(vector1, MAX_SIZE);
    printf("elemento: %d\n", elemento_que_mas_se_repite);
    return 0;
}
