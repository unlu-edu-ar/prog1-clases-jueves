#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("La cantidad de argumentos es: %i\n", argc);
    printf("El primer argumento es el nombre del ejecutable: %s\n", argv[0]);
    printf("Hola %s \n", argv[1]);
    return 0;
}

// Compilar con comando gcc testArgs.c -o testArgs
// Ejecutar con comando testArgs argumento1 argumento2
// En linux Ejecutar con comando ./testArgs argumento1 argumento2
