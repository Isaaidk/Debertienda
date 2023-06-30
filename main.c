#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 100
#define MAX_DESCRIPCION 100

void ingresarProducto(char* nombres[], char* descripciones[], float* precios, int indice);
void editarProducto(char* nombres[], char* descripciones[], float* precios, int indice);
void mostrarProductos(char* nombres[], char* descripciones[], float* precios, int cantidad);

int main() {
    char* nombres[MAX_PRODUCTOS];
    char* descripciones[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];

    int opcion, indice = 0;

    do {
        printf("------- Menu -------\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Mostrar productos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, descripciones, precios, indice);
                indice++;
                break;
            case 2:
                if (indice > 0) {
                    int indiceEditar;
                    printf("Ingrese el indice del producto a editar (0-%d): ", indice - 1);
                    scanf("%d", &indiceEditar);
                    editarProducto(nombres, descripciones, precios, indiceEditar);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
            case 3:
                if (indice > 0) {
                    mostrarProductos(nombres, descripciones, precios, indice);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 4);

    return 0;
}

void ingresarProducto(char* nombres[], char* descripciones[], float* precios, int indice) {
    char nombre[MAX_NOMBRE];
    char descripcion[MAX_DESCRIPCION];
    float precio;

    nombres[indice] = (char*)malloc(MAX_NOMBRE * sizeof(char));
    descripciones[indice] = (char*)malloc(MAX_DESCRIPCION * sizeof(char));

    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombre);
    strcpy(nombres[indice], nombre);

    printf("Ingrese la descripcion del producto: ");
    scanf(" %[^\n]", descripcion);
    strcpy(descripciones[indice], descripcion);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    precios[indice] = precio;

    printf("Producto ingresado con exito.\n");
}

void editarProducto(char* nombres[], char* descripciones[], float* precios, int indice) {
    char nombre[MAX_NOMBRE];
    char descripcion[MAX_DESCRIPCION];
    float precio;

    printf("Ingrese el nuevo nombre del producto: ");
    scanf(" %[^\n]", nombre);
    strcpy(nombres[indice], nombre);

    printf("Ingrese la nueva descripcion del producto: ");
    scanf(" %[^\n]", descripcion);
    strcpy(descripciones[indice], descripcion);

    printf("Ingrese el nuevo precio del producto: ");
    scanf("%f", &precio);
    precios[indice] = precio;

    printf("Producto editado con exito.\n");
}

void mostrarProductos(char* nombres[], char* descripciones[], float* precios, int cantidad) {
    printf("------- Productos -------\n");
    for (int i = 0; i < cantidad; i++) {
        printf("------- Producto %d -------\n", i);
        printf("Nombre: %s\n", nombres[i]);
        printf("Descripcion: %s\n", descripciones[i]);
        printf("Precio: %.2f\n", precios[i]);
    }
}
