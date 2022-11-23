// Una empresa de colectivos tiene organizada su información en los siguientes
// vectores:
// INTERNOS (vector de registros): datos de las líneas internas de la empresa
// de colectivo
// RECORRIDOS (vector de enteros): datos de la longitud en km de los recorridos

// Los registros del vector INTERNOS tienen la siguiente forma:
// Número de interno: Integer (1001 al 3000, consecutivos)
// Km recorridos: integer
// Dinero recaudado: float

// El vector de recorridos (vector de enteros de longitud 10)  contiene la
// longitud en Kilómetros de cada uno de los 10 recorridos. El índice del vector
// indica el código del recorrido. La longitud en km de los recorridos es
// [12,9,13,10,8,7,9,22,11,5]

// Se cuenta además con un archivos de texto MENSUAL.TXT con la siguiente información:
// Día: Integer (1 al 30)
// Número de interno: integer (1001 al 3000)
// Código recorrido: integer (del 0 al 9)
// Pasajeros transportados: integer
// Recaudación: float
// El archivo MENSUAL.TXT está agrupado por Número de Interno.

// Se pide:

// 1) Crear las estructuras de datos INTERNOS y RECORRIDOS.
// Inicializar el vector RECORRIDOS con los datos de las longitudes en kilómetros
// de los recorridos.
// Inicializar el vector INTERNOS con los registros correspondientes, donde los
// números de interno deben tener numeración consecutiva del 1001 al 3000, y los
// kilómetros recorridos y el dinero recaudado deben estar inicializados en forma
// random del 10 al 100.

// 2) Procesar el archivo MENSUAL.TXT, utilizando la técnica de corte de control para:
// a) actualizar la recaudación y los kilómetros recorridos del vector INTERNOS
// b) Informar por pantalla el recorrido que más recaudó ese mes.

// Restricción: El archivo MENSUAL.TXT puede leerse por completo SOLAMENTE UNA VEZ
// en todo el programa durante el corte de Control.

// Es un error descalificante actualizar cualquiera de los vectores de registros
// por cada lectura del archivo de texto.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 2000

typedef struct  // 1
{
    int num_interno; // 1001 a 3000 consecutivos
    int km_recorr;
    float dinero_recaud;
} t_internos;

typedef t_internos t_tabla_internos[MAX];
// Se cuenta además con un archivos de texto MENSUAL.TXT con la siguiente información:
// Día: Integer (1 al 30)
// Número de interno: integer (1001 al 3000)
// Código recorrido: integer (del 0 al 9)
// Pasajeros transportados: integer
// Recaudación: float
// El archivo MENSUAL.TXT está agrupado por Número de Interno.

void cargar_internos(t_internos *internos);
int main()
{
    FILE *fp;
    
    int recorridos[10] = {12, 9, 13, 10, 8, 7, 9, 22, 11, 5};
    t_tabla_internos tabla_internos;
    t_internos interno;
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX; i++)
    {
        //cargar_internos(&(tabla_internos[i]));
        interno.num_interno = i  + 1001;
        interno.dinero_recaud = 10 + rand() % 100;
        interno.km_recorr = 10 + rand() % 100;
        tabla_internos[i] = interno;
    }
    // 2 corte de control 
    mensual(recorridos, tabla_internos);
}

void cargar_internos(t_internos *internos)
{
    printf("Datos internos: \n\n");
    printf("Numero de interno: [del 1001 al 3000,consecutivos]\n");
    scanf("%i", (*internos).num_interno);
    getc(stdin);
    printf("Kilometros recorridos: \n");
    scanf("%i", (*internos).km_recorr);
    getc(stdin);
    (*internos).dinero_recaud = 10 + rand() % 100;
    getc(stdin);
}
// 2) Procesar el archivo MENSUAL.TXT, utilizando la técnica de corte de control para:
// a) actualizar la recaudación y los kilómetros recorridos del vector INTERNOS
// b) Informar por pantalla el recorrido que más recaudó ese mes.

void mensual(int * recorridos, t_internos * internos)
{
    FILE * fp = fopen("MENSUAL.TXT", "r");
    
    int dia;
    int numero_interno;
    int codigo_recorrido;
    int pasajeros_transport;
    float recaudacion;
    int recaudacion_max;
    int es;
    int recorrido_max;

    float recaudacion_por_recorrido[10] = {0};
    float recaudacion_por_interno[2000] = {0};
    float km_recorridos_por_interno[2000] = {0};

    fscanf(fp, "%i%i%i%i%f", &dia, &numero_interno, &codigo_recorrido, &pasajeros_transport, &recaudacion);
    while (!feof(fp))
    {
        int num_ant_intern = numero_interno;
        float suma_recaudacion = 0;
        int suma_km = 0;
        while ((!feof(fp)) && num_ant_intern == numero_interno)
        {
            recaudacion_por_recorrido[codigo_recorrido] += recaudacion;
            suma_recaudacion += recaudacion;
            suma_km = suma_km + recorridos[codigo_recorrido];
            fscanf(fp, "%i%i%i%i%f", &dia, &numero_interno, &codigo_recorrido, &pasajeros_transport, &recaudacion);
        }
        recaudacion_por_interno[num_ant_intern - 1001] = suma_recaudacion;
        km_recorridos_por_interno[num_ant_intern - 1001] = suma_km;
    }
    float mayor = recaudacion_por_recorrido[0];
    int indice_mayor = 0;
    for (int i = 1; i < 10; i++)
    {
        if (mayor < recaudacion_por_recorrido[i])
        {
            mayor = recaudacion_por_recorrido[i];
            indice_mayor = i;
        }
        
    }
    printf("El recorrido con mayor recaudación es: %i", indice_mayor); 
    fclose(fp);
    // Abrir el archivo binario
    for (int i = 0; i < 2000; i++)
    {
        // t_internos interno;
        // // Posicionarnos en la posicion donde dice el codigo
        // fseek(fp, sizeof(t_internos)*i, SEEK_SET);
        // fread(&interno, sizeof(t_internos), 1, fp);

        internos[i].km_recorr += km_recorridos_por_interno[i];
        internos[i].dinero_recaud += recaudacion_por_interno[i];

        // // Posicionarnos en la posicion donde dice el codigo
        // fseek(fp, -sizeof(t_internos), SEEK_CUR);
        // // Actualizar el registro en el archivo binario
        // fwrite(&interno, sizeof(t_internos), 1, fp);
    }
    // Cerrar el archivo binario
}
