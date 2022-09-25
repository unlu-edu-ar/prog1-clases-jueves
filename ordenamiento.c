#include <stdio.h>
#include <stdlib.h>

void ordenar_burbuja(int datos[], int n) {
    int i, j, nointer, aux;
    nointer = 0;
    for(i=0; i<n && nointer==0;i++)  {
        nointer=1;
        for (j = 1; j <n - i; j++){
            if (datos[j-1] > datos[j]) {                /* Intercambio */
                aux = datos[j];
                datos[j] = datos[j-1];
                datos[j-1] = aux;
                nointer=0;
            }
        }
    }
}

void ordenar_seleccion(int datos[], int n) {
    int i, j, aux;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (datos[i] > datos[j]) {
                /* Intercambio */
                aux = datos[i];
                datos[i] = datos[j];
                datos[j] = aux;
            }
}

void ordenar_insercion(int datos[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        j=i;
        while ((j >0) && (datos[j-1] >datos[j])) {
            temp = datos[j-1];
            datos[j-1] = datos[j];
            datos[j] = temp;
            j=j-1;
        }
    }
} 

void selection_sort(int * datos, int taille)
{
     int actual, mas_pequeno, j, temp;
 
     for (actual = 0; actual < taille - 1; actual++)
     {
         mas_pequeno = actual;
         for (j = actual; j < taille; j++)
              if (datos[j] < datos[mas_pequeno])
                  mas_pequeno = j;
          temp = datos[actual];
          datos[actual] = datos[mas_pequeno];
          datos[mas_pequeno] = temp;
     }
}


void mostrar(int * matriz, int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("%i ", matriz[i]);
    }
    printf("\n");
}

int main()
{
    int vector[] = {3,2,4,5,10,9,1,6, 8, 7};
    mostrar(vector, 10);

    selection_sort(vector, 10);

    mostrar(vector, 10);

    return 0;
}

