#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
} Product;

void printProduct(const Product* product) {
    printf("Nombre: %s\n", product->name);
    printf("Descripción: %s\n", product->description);
    printf("Precio: %.2f\n", product->price);
    printf("\n");
}

int main() {
    Product* products[MAX_PRODUCTS];
    int productCount = 0;
    char choice;

    do {
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Mostrar productos\n");
        printf("4. Salir\n");
        printf("Ingrese su elección: ");
        scanf(" %c", &choice);
        printf("\n");

        switch (choice) {
            case '1':
                if (productCount < MAX_PRODUCTS) {
                    products[productCount] = (Product*)malloc(sizeof(Product));

                    printf("Ingrese el nombre del producto: ");
                    scanf("%s", products[productCount]->name);

                    printf("Ingrese la descripción del producto: ");
                    scanf("%s", products[productCount]->description);

                    printf("Ingrese el precio del producto: ");
                    scanf("%f", &(products[productCount]->price));

                    productCount++;
                    printf("Producto agregado correctamente.\n\n");
                } else {
                    printf("No se pueden agregar más productos.\n\n");
                }
                break;

            case '2':
                if (productCount > 0) {
                    int index;
                    printf("Ingrese el índice del producto a editar (0-%d): ", productCount - 1);
                    scanf("%d", &index);
                    printf("\n");

                    if (index >= 0 && index < productCount) {
                        printf("Ingrese el nuevo nombre del producto: ");
                        scanf("%s", products[index]->name);

                        printf("Ingrese la nueva descripción del producto: ");
                        scanf("%s", products[index]->description);

                        printf("Ingrese el nuevo precio del producto: ");
                        scanf("%f", &(products[index]->price));

                        printf("Producto editado correctamente.\n\n");
                    } else {
                        printf("Índice inválido.\n\n");
                    }
                } else {
                    printf("No hay productos para editar.\n\n");
                }
                break;

            case '3':
                if (productCount > 0) {
                    printf("Lista de productos:\n\n");
                    for (int i = 0; i < productCount; i++) {
                        printf("Producto %d:\n", i);
                        printProduct(products[i]);
                    }
                } else {
                    printf("No hay productos para mostrar.\n\n");
                }
                break;

            case '4':
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente de nuevo.\n\n");
                break;
        }
    } while (choice != '4');

    // Liberar la memoria asignada a los productos
    for (int i = 0; i < productCount; i++) {
        free(products[i]);
    }

    return 0;
}
