#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FIL 10
#define MAX_COL 10

// Escriba una función que reciba como parámetros una matriz de m filas y n columnas (donde n es par) y 
// todos los elementos de la matriz son números pares y la retorne con los valores cambiados de modo que 
// los nuevos valores sean el resultado de sumarle a cada elemento el promedio de su respectiva fila.

// Nota: No hace falta validar los valores pares.

// Por ejemplo, si la matriz a es:
// 2  6  8  4 (promedio fila es 5)
// 4  0  2  6 (promedio fila es 3)
// 8  0  2  6 (promedio fila es 4)
// retorna la matriz
//   7 11 13  9     (Se le sumó 5 a cada elemento )
//   7  3   5   9    (Se le sumó 3 a cada elemento )
// 12  4   6 10    (Se le sumó 4 a cada elemento )

// Nota: El tamaño de la matriz es M x N no exactamente 3 x 4 como el ejemplo.

void cargaAleatoria(int matriz[MAX_FIL][MAX_COL], int fil, int col);
void mostrarArreglo(int matriz[MAX_FIL][MAX_COL], int fil, int col);
void sumarPromedio(int matriz[MAX_FIL][MAX_COL], int fil, int col);
void modificarMatriz(int matriz[MAX_FIL][MAX_COL], int fil, int col, int arreglo[]);

int main(void) {
    int matriz1[MAX_FIL][MAX_COL] = {};
    int matriz2[MAX_FIL][MAX_COL] = {};
    srand(time(NULL));
    cargaAleatoria(matriz1, 3, 4);
    printf("Matriz Inicializada \n");
    mostrarArreglo(matriz1, 3, 4);
    sumarPromedio(matriz1, 3, 4);
    printf("Matriz Modificada \n");
    mostrarArreglo(matriz1, 3, 4);
    return 0;
}

void cargaAleatoria(int matriz[MAX_FIL][MAX_COL], int fil, int col) {
    int numero_aleatorio;
    for(int i = 0; i < fil; i++) {
        for(int j = 0; j < col; j++) {
            numero_aleatorio = (rand() % 5) * 2;
            matriz[i][j] = numero_aleatorio;
        }
    }
}

void mostrarArreglo(int matriz[MAX_FIL][MAX_COL], int fil, int col) {
    for(int i = 0; i < fil; i++) {
        for(int j = 0; j < col; j++) {
            printf("%i \t", matriz[i][j]);
        }
        printf("\n");
    } 
}

void sumarPromedio(int matriz[MAX_FIL][MAX_COL], int fil, int col) {
    int promedios[fil];
    int promedio_fila;
    int total;
    for(int i = 0; i < fil; i++) {
        total = 0;
        for(int j = 0; j < col; j++) {
            total += matriz[i][j];    
        }
        promedio_fila = total / col;
        promedios[i] = promedio_fila;
    }
    modificarMatriz(matriz, fil, col, promedios);
}

void modificarMatriz(int matriz[MAX_FIL][MAX_COL], int fil, int col, int arreglo[]) {
    for(int i = 0; i < fil; i++) {
        for(int j = 0; j < col; j++) {
            matriz[i][j] += arreglo[i];    
        }
    }
}
