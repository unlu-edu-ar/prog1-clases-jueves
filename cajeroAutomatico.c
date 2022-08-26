/* Realice un programa que simule el funcionamiento de un cajero
automático. El mismo contará con las siguientes operaciones: consulta
de saldo, carga y retiro de dinero. Antes de retirar, se debe validar que
dicho monto exista dentro de la cuenta. El saldo inicial es de $5.000.
Además, se desea contar con un menú que facilite la interacción con el
usuario y que le permita finalizar la ejecución cuando lo desee.*/ 

#include <stdio.h>
#include <stdlib.h>

void consultarSaldo(float dinero) {
    printf("Su saldo es: %f \n", dinero);
}

void cargarDinero(float *dinero) {
    float deposito;
    printf("Cuanto dinero desea depositar? ");
    scanf("%f", &deposito);
    *dinero += deposito;
}

float retirarDinero(float dinero) {
    float retiro;
    printf("Cuanto dinero desea retirar? ");
    scanf("%f", &retiro);
    if(retiro > dinero) {
        printf("Ha ingresado un monto superior al de su cuenta \n");
    }else if (retiro <= 0) {
        printf("El monto ingresado no es valido \n");
    }
    else {
        dinero -= retiro;
    }
    return dinero;
}

void Menu(void) {
    system("cls");
    printf("1. Consultar saldo \n");
    printf("2. Cargar dinero \n");
    printf("3. Retirar dinero \n");
    printf("4. Salir \n");
    printf("Por favor seleccione una opcion: \n");
}

int main(void) {
    int opcion;
    float saldo = 5000;
    do {
        Menu();
        scanf("%i", &opcion);
        switch(opcion){
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                cargarDinero(&saldo); // Pasamos el saldo por referencia para poder modificar su valor. Operamos sobre la variable.                      
                break;
            case 3:
                saldo = retirarDinero(saldo); // Pasamos el saldo por valor. Operamos sobre una copia y las operaciones no afectan a la variable original.
                break;
            case 4:
                printf("Nos vemos despues \n");
                break;
            default:
                printf("Ha ingresado una opcion incorrecta \n");
        }
        system("Pause");
    }while (opcion != 4);
    
    return 0;
    

}
