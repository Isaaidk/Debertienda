#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 100
#define MAX_DESCRIPCION 100

void ingresarProducto(char* nombres[], char* descripciones[], float precios[], int* cantidad);
void editarProducto(char* nombres[], char* descripciones[], float precios[], int cantidad);
void mostrarProductos(char* nombres[], char* descripciones[], float precios[], int cantidad);
void eliminarProducto(char* nombres[], char* descripciones[], float precios[], int* cantidad, int indice);

int main() {
    char* nombres[MAX_PRODUCTOS];
    char* descripciones[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int cantidad = 0;

    int opcion;

    do {
        printf("------- Menu -------\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Mostrar productos\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, descripciones, precios, &cantidad);
                break;
            case 2:
                editarProducto(nombres, descripciones, precios, cantidad);
                break;
            case 3:
                mostrarProductos(nombres, descripciones, precios, cantidad);
                break;
            case 4:
                if (cantidad > 0) {
                    int indiceEliminar;
                    printf("Ingrese el indice del producto a eliminar (0-%d): ", cantidad - 1);
                    scanf("%d", &indiceEliminar);
                    eliminarProducto(nombres, descripciones, precios, &cantidad, indiceEliminar);
                } else {
                    printf("No hay productos ingresados.\n");
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    // Liberar la memoria asignada para las descripciones y nombres
    for (int i = 0; i < cantidad; i++) {
        free(nombres[i]);
        free(descripciones[i]);
    }

    return 0;
}

void ingresarProducto(char* nombres[], char* descripciones[], float precios[], int* cantidad) {
    if (*cantidad < MAX_PRODUCTOS) {
        char nombre[MAX_NOMBRE];
        char descripcion[MAX_DESCRIPCION];
        float precio;

        nombres[*cantidad] = (char*)malloc(MAX_NOMBRE * sizeof(char));
        descripciones[*cantidad] = (char*)malloc(MAX_DESCRIPCION * sizeof(char));

        printf("Ingrese el nombre del producto: ");
        scanf(" %[^\n]", nombre);
        strcpy(nombres[*cantidad], nombre);

        printf("Ingrese la descripcion del producto: ");
        scanf(" %[^\n]", descripcion);
        strcpy(descripciones[*cantidad], descripcion);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &precio);
        precios[*cantidad] = precio;

        printf("Producto ingresado con exito.\n");

        (*cantidad)++;
    } else {
        printf("No es posible ingresar mas productos. Se alcanzo el limite maximo.\n");
    }
}

void editarProducto(char* nombres[], char* descripciones[], float precios[], int cantidad) {
    if (cantidad > 0) {
        int indice;
        printf("Ingrese el indice del producto a editar (0-%d): ", cantidad - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < cantidad) {
            printf("------- Editar Producto -------\n");

            printf("Nombre actual: %s\n", nombres[indice]);
            printf("Ingrese el nuevo nombre del producto: ");
            scanf(" %[^\n]", nombres[indice]);

            printf("Descripcion actual: %s\n", descripciones[indice]);
            printf("Ingrese la nueva descripcion del producto: ");
            scanf(" %[^\n]", descripciones[indice]);

            printf("Precio actual: %.2f\n", precios[indice]);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precios[indice]);

            printf("Producto editado con exito.\n");
        } else {
            printf("Indice invalido. No se puede editar el producto.\n");
        }
    } else {
        printf("No hay productos ingresados.\n");
    }
}

void mostrarProductos(char* nombres[], char* descripciones[], float precios[], int cantidad) {
    printf("------- Productos -------\n");
    if (cantidad > 0) {
        for (int i = 0; i < cantidad; i++) {
            printf("------- Producto %d -------\n", i);
            printf("Nombre: %s\n", nombres[i]);
            printf("Descripcion: %s\n", descripciones[i]);
            printf("Precio: %.2f\n", precios[i]);
        }
    } else {
        printf("No hay productos ingresados.\n");
    }
}

void eliminarProducto(char* nombres[], char* descripciones[], float precios[], int* cantidad, int indice) {
    if (indice >= 0 && indice < *cantidad) {
        // Liberar la memoria asignada para el nombre y descripción del producto a eliminar
        free(nombres[indice]);
        free(descripciones[indice]);

        // Desplazar los elementos restantes hacia atrás para llenar el espacio vacío
        for (int i = indice; i < *cantidad - 1; i++) {
            nombres[i] = nombres[i + 1];
            descripciones[i] = descripciones[i + 1];
            precios[i] = precios[i + 1];
        }

        (*cantidad)--;

        printf("Producto eliminado con exito.\n");
    } else {
        printf("Indice invalido. No se puede eliminar el producto.\n");
    }
}
