#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 4

// Hacer un programa que almacene en un arreglo de registros la siguiente información de N trabajadores: 
// nombre, edad, sexo (F o M), estado civil(S(soltero), C(casado), D(divorciado) y O(otro)) y salario base.  
// Calcular y mostrar por pantalla la cantidad de trabajadores del sexo masculino, la cantidad de trabajadoras 
// casadas, el nombre del/a empleado/a más joven y la suma de todos los salarios.

typedef struct {
    char nombre;
    int edad;
    char sexo;
    char estado_civil;
    float salario;
}trabajador;

typedef trabajador tabla_trabajadores[MAX];
typedef int tabla_enteros[MAX];

void cargarTrabajador(trabajador* empleado);


int main (void) {

    tabla_trabajadores Empleados;
    int cantidad_masculinos = 0;
    int cantidad_casadas = 0;
    char mas_joven;
    int menor_edad = 100;
    float salarios = 0;
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        cargarTrabajador(&Empleados[i]);
        printf("%c - %c - %c - %i - %f \n", Empleados[i].sexo, Empleados[i].estado_civil, Empleados[i].nombre, Empleados[i].edad, Empleados[i].salario);
        if (Empleados[i].sexo == 'M') cantidad_masculinos++;
        else if(Empleados[i].estado_civil == 'C') cantidad_casadas++;
        salarios += Empleados[i].salario;
        if(Empleados[i].edad < menor_edad) {
            menor_edad = Empleados[i].edad;
            mas_joven = Empleados[i].nombre;
        }

    }
    printf("La cantidad de trabajadores masculinos es: %i \n", cantidad_masculinos);
    printf("La cantidad de trabajadoras casadas es: %i \n", cantidad_casadas);
    printf("El empleado mas joven es %c y tiene %i \n", mas_joven, menor_edad);
    printf("La suma de todos los salarios es %f", salarios);




    return 0;
}

void cargarTrabajador(trabajador* empleado) {
    char sexos[2] = {'F', 'M'};
    char estados[4] = {'S', 'C', 'D', 'O'};
    char iniciales[5] = {'A', 'B', 'C', 'D', 'E'};
    empleado->sexo = sexos[rand() % 2];
    empleado->estado_civil = estados[rand() % 4];
    empleado->salario = rand() % 1000 + 1;
    empleado->nombre = iniciales[rand() % 5];
    empleado->edad = rand() % 70 + 18;
}
