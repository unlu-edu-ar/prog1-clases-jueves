#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5


// Consigna: Escriba una función que reciba como parámetros tres vectores de enteros v1, v2 y v3, 
// un entero op, y RETORNE en el vector v3 la concatenación invertida de v1 y v2, empezando por v1, 
// si op=1, y empezando por v2 si op=2.
// Por ejemplo: Si v1= [1,4,7], v2=[8,0], v3[0,0,0,0,0]
// Si op=1, la función debería poner en v3[7,4,1,0,8].
// Si op=2, la función debería poner en v3[0,8,7,4,1].

void concatenacionInvertida(int v1[], int v2[], int v3[], int cantidadV1, int cantidadV2, int op);
void cargaAleatoria(int arreglo[], int cantidad);
void mostrarArreglo(int arreglo[], int cantidad);

int main(void) {
    int arreglo1[MAX] = {}; 
    int arreglo2[MAX] = {}; 
    int arreglo3[MAX*2] = {};
    srand(time(NULL));
    cargaAleatoria(arreglo1, MAX);
    cargaAleatoria(arreglo2, MAX);
    printf("Arreglo 1: \t");
    mostrarArreglo(arreglo1, MAX);
    printf("\nArreglo 2: \t");
    mostrarArreglo(arreglo2, MAX);
    concatenacionInvertida(arreglo1, arreglo2, arreglo3, MAX, MAX, 2);
    printf("\nArreglo Resultado: \t");
    mostrarArreglo(arreglo3, MAX*2);
    return 0;
}

void concatenacionInvertida(int v1[], int v2[], int v3[], int cantidadV1, int cantidadV2, int op) {
    int elemento_actual;
    int j = 0;
    if (op == 1) {
        for(int i = cantidadV1-1; i >= 0; i--) {
            elemento_actual = v1[i];
            v3[j] = elemento_actual;
            j++;
        }
        for(int i = cantidadV2-1; i >= 0; i--) {
            elemento_actual = v2[i];
            v3[j] = elemento_actual;
            j++;
        }
    } 
    else {
        for(int i = cantidadV2-1; i >= 0; i--) {
            elemento_actual = v2[i];
            v3[j] = elemento_actual;
            j++;
        }
        for(int i = cantidadV1-1; i >= 0; i--) {
            elemento_actual = v1[i];
            v3[j] = elemento_actual;
            j++;
        }
    }
}

void cargaAleatoria(int arreglo[], int cantidad) {
    int numero_aleatorio;
    for(int i = 0; i < cantidad; i++) {
        numero_aleatorio = rand() % 10 + 1;
        arreglo[i] = numero_aleatorio;
    }
}

void mostrarArreglo(int arreglo[], int cantidad) {
    for(int i = 0; i < cantidad; i++) {
        printf("%i ", arreglo[i]);
    }
}
