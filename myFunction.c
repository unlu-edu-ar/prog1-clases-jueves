#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 3
#define COLUMNAS 3

void mostrarVector(int * matriz, int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("%i ", matriz[i]);
    }
    printf("\n");
}

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            printf("%i  ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void randomMatriz(int matriz[][COLUMNAS], int filas, int columnas, int until){
    srand(time(NULL));
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            matriz[i][j] = rand() % until;
        }
    }
}
