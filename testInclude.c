#include <stdio.h>
#include <stdlib.h>
#include "myFunction.c"

int main()
{
    int matriz[FILAS][COLUMNAS];

    randomMatriz(matriz, FILAS, COLUMNAS, 50);
    printf("Matriz: \n");
    mostrarMatriz(matriz, FILAS, COLUMNAS);
    return 0;
}
