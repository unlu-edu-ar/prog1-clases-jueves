#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIA 31
#define MES 12
#define ANIO 9


// 1) Crear un calendario que nos permita agendar días
// 2) Luego mostrar los días que tenemos agendado algo
// 3) Preguntar si algún DIA en particular está ocupado

void agendarDia(int c[ANIO][MES][DIA], int a, int m, int d);
void mostrarDia(int c[ANIO][MES][DIA]);
void preguntarDia(int c[ANIO][MES][DIA], int a, int m, int d);

int main(void) {
    
    int calendario[ANIO][MES][DIA] = {};
    int dia, mes, anio;
    
    mostrarDia(calendario);
    agendarDia(calendario, 5, 5, 7);   // Se carga en orden: año/mes/dia
    agendarDia(calendario, 1, 6, 3);
    agendarDia(calendario, 2, 8, 4);
    
    mostrarDia(calendario);   // Se muestra dia/mes/año
    preguntarDia(calendario, 5, 5, 7);
    preguntarDia(calendario, 1, 1, 2);
    preguntarDia(calendario, 1, 6, 3);
    


    return 0;
}

void agendarDia(int c[ANIO][MES][DIA], int a, int m, int d) {
    c[a][m-1][d-1] = 1;   // 1 significa que el día está ocupado
}

void mostrarDia(int c[ANIO][MES][DIA]) {
    int contador = 0;
    int anio_actual, mes_actual, dia_actual;
    for(anio_actual = 0; anio_actual < ANIO; anio_actual++) {
        for(mes_actual = 0; mes_actual < MES; mes_actual++) {
            for(dia_actual = 0; dia_actual < DIA; dia_actual++) {
                if(c[anio_actual][mes_actual][dia_actual] == 1) {
                    printf("%i/%i/%i \n",dia_actual+1, mes_actual+1, anio_actual);
                    contador++;
                }
            }
        }
    }
    printf("Estas ocupado %i dias \n", contador);
}

void preguntarDia(int c[ANIO][MES][DIA], int a, int m, int d) {
    if(c[a][m-1][d-1] == 1) {
        printf("Ese dia estas ocupado \n");
    }
    else {
        printf("Ese dia estas libre \n");
    }
}
