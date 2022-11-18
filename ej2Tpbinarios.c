// Se cuenta con un archivo de texto “movi.txt”  que contiene un conjunto de facturas y la cantidad de artículos vendidos en cada una de ellas. 
// Se encuentra ordenado por número de factura. 
// archivo “movi.txt”  
// Nro. de factura 
// Código de artículo (1001 – 2000) 
// Cantidad vendida  
// Además, en el archivo “produ.dat” , se encuentra almacenado el código (clave primaria), el precio unitario de cada artículo y el stock actual.  
// archivo “produ.dat”  
// - Cód. Artículo…..integer 
// - Precio…………...real 
// - Stock…………....integer 
// Realizar los procedimientos y/o funciones necesarios para:  
// 1-Crear los dos archivos.
// 2-Imprimir un listado que contenga: Nro. de factura (una sola vez por factura), los artículos vendidos para cada factura, la cantidad, 
// el precio unitario y el precio total de cada artículo y el monto total de la factura. Se deben realizar pausas cada vez que sea necesario. 
// 3-Con los datos de “movi.txt” actualizar el stock productos.dat”. 
 //NOTAS:
// El archivo binario se encuentra ordenado eficientemente y posee datos válidos desde el registro 1
// (el registro ubicado en la posición 1 del archivo corresponde al producto cuyo código es 1001).
// El archivo “movi.txt” puede leerse una única vez en todo el programa.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

typedef struct
{
    int codigo_articulo;
    float precio;
    int stock;
} t_producto;


void crear_archivo_movi(int count){
    FILE * fp = fopen("movi.txt", "w");
    for (int i = 0; i < count; i++)
    {
        int codigo_articulo =  (rand() % 20) + 1001;
        int cantidad_vendida = rand() % 30;
        fprintf(fp, "%i %i %i\n", i, codigo_articulo, cantidad_vendida);
    }
    fclose(fp);
}

void crear_archivo_producto(int count){
    FILE * fp = fopen("produ.dat", "wb");
    t_producto producto;
    for (int i = 0; i < count; i++)
    {
        producto.codigo_articulo = i + 1001;
        producto.precio = (rand() % 1000) + 100;
        producto.stock = rand() % 1000;
        fwrite(&producto, sizeof(t_producto), 1, fp);
    }
    
    fclose(fp);
}

float obtener_precio(int codigo_articulo){
    FILE * fp = fopen("produ.dat", "rb");
    int posicion = codigo_articulo - 1000 - 1;
    fseek(fp, posicion * sizeof(t_producto), SEEK_SET);
    t_producto producto;
    fread(&producto, sizeof(t_producto), 1, fp);
    fclose(fp);
    return producto.precio;
}

void actualizar_stock(int codigo_articulo, int cantidad_vendida){
    FILE * fp = fopen("produ.dat", "r+b");
    int posicion = codigo_articulo - 1000 - 1;
    fseek(fp, posicion * sizeof(t_producto), SEEK_SET);
    t_producto producto;
    fread(&producto, sizeof(t_producto), 1, fp);
    if (producto.stock - cantidad_vendida >= 0)
    {
        producto.stock -= cantidad_vendida;
        fseek(fp, -sizeof(t_producto), SEEK_CUR);
        fwrite(&producto, sizeof(t_producto), 1, fp);
    }
    
    fclose(fp);
}

void imprimir_listado(){
    FILE * fp = fopen("movi.txt", "r");
    int numero_factura;
    int codigo_articulo;
    int cantidad_vendida;
    while (!feof(fp))
    {
       //fprintf(fp, "%i %i %i\n", i, codigo_articulo, cantidad_vendida); 
       fscanf(fp, "%i %i %i\n", &numero_factura, &codigo_articulo, &cantidad_vendida);
       float precio_unitario = obtener_precio(codigo_articulo);
       float precio_total = cantidad_vendida * precio_unitario;
       printf("%i %i %i %2.f %2.f \n", numero_factura, codigo_articulo, cantidad_vendida, precio_unitario, precio_total);
       actualizar_stock(codigo_articulo, cantidad_vendida);
    }
    fclose(fp);
}

void mostrar_productos(){
    FILE * fp = fopen("produ.dat", "rb");
    t_producto producto;
    while (!feof(fp))
    {
        fread(&producto, sizeof(t_producto), 1, fp);
        printf("cod: %i, precio: %2.f, stock: %i \n", producto.codigo_articulo, producto.precio, producto.stock);
    }
    fclose(fp);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    //crear_archivo_movi(20);
    //crear_archivo_producto(20);
    mostrar_productos();
    imprimir_listado();
    mostrar_productos();

    return 0;
}
