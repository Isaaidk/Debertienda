#include <stdio.h>

float mora=0;
float *puntero1 = &mora;

float peras=0;
float *puntero2 = &peras;

float uva=0;
float *puntero3 = &uva;

float naran=0;
float *puntero4 = &naran;

float kiwi=0;
float *puntero5 = &kiwi;

float n2, n3, n5,prM,prP,prU,prNA,prK;
float n4;
float suma=0;
float *punterosum = &suma;

float suma2=0;
float *punterosum2= &suma2;

int main() {




    char opcion;













    float n1 = 0;




    do {
        printf("***BIENVENIDO A LOS ABARROTES DON JUAN****\n");

        printf("***MENU****\n");

        printf("1)  Productos \n");

        printf("2) Eliminacion de productos  \n");

        printf("3) Factura - fin del programa \n");

        printf("\n");

        scanf("%s", &opcion);

        switch (opcion) {

            case '1':

                do {

                    printf("Escoja los productos que desea facturar: \n");

                    printf("a) Mora (Precio: $1.15 libra )\n");

                    printf("b) Peras (Precio: $1.50 libra)\n");

                    printf("c) Uvas (Precio: $2.00 libra )\n");

                    printf("d) Naranjas (Precio: $1.10 libra)\n");

                    printf("e) Kiwi (Precio: $1.20)\n");

                    scanf("%s", &opcion);


                    switch (opcion) {

                        case 'a':

                            printf("ingrese la cantidad de libras de mora; \n\n");

                            scanf("%f", &mora);

                            *puntero1= mora;

                            break;

                        case 'b':

                            printf("Ingrese la cantidad de libras de pera: \n\n");

                            scanf("%f", &peras);

                            *puntero2= peras;

                            break;

                        case 'c':

                            printf("Ingrese la cantidad de libras de uva: \n\n");

                            scanf("%f", &uva);

                            *puntero3= uva;

                            break;

                        case 'd':

                            printf("Ingrese la cantidad de libras de naranjas: \n\n");

                            scanf("%f", &naran);

                            *puntero4= naran;

                            break;

                        case 'e':

                            printf("Ingrese la cantidad de libras de kiwi : \n\n");

                            scanf("%f", &kiwi);

                            *puntero5= kiwi;

                            break;

                    }


                    printf("Desea facturar otro producto (S/N):\n\n ");

                    scanf(" %c", &opcion);

                } while (opcion == 'S' || opcion == 's');

                break;

            case '2':

                printf("Escoja los productos que desea eliminar: \n");

                printf("a) Mora %.0f \n",mora);

                printf("b) Peras %.0f\n",peras);

                printf("c) Uvas %.0f\n",uva);

                printf("d) Naranjas %.0f \n",naran);

                printf("e) Kiwi %.0f \n",kiwi);





                    scanf("%s", &opcion);


                    switch (opcion) {

                        case 'a':

                            printf(" Cuantas libras de mora desea eliminar; \n\n");


                            scanf("%f", &n1);

                            *puntero1= *puntero1 -n1;
                            printf("Producto eliminado, total de libras de moras: %.0f\n\n",mora);

                            break;

                        case 'b':
                            printf(" Cuantas libras de pera desea eliminar; \n\n");


                            scanf("%f", &n2);

                            *puntero2= *puntero2 -n2;

                            printf("Producto eliminado, total de libras de peras: %.0f\n\n",peras);


                            break;

                        case 'c':

                            printf(" Cuantas libras de uvas desea eliminar; \n\n");


                            scanf("%f", &n3);

                            *puntero3= *puntero3 -n3;
                            printf("Producto eliminado, total de libras de uvas: %.0f\n\n",uva);


                            break;


                        case 'd':

                            printf(" Cuantas libras de naranjas desea eliminar; \n\n");


                            scanf("%f", &n4);

                            *puntero4 = *puntero4 - n4;
                            printf("Producto eliminado, total de libras de naranjas: %.0f\n\n",naran);

                            break;

                        case 'e':

                            printf(" Cuantas libras de kiwi desea eliminar; \n\n");


                            scanf("%f", &n5);

                            *puntero5 = *puntero5 - n5;

                            printf("Producto eliminado, total de libras de kiwis: %.0f\n\n",kiwi);
                            break;
                    }




                break;

            case '3':
                prM=mora*1.15;
                prP=peras*1.50;
                prU=uva*2.00;
                prNA=naran*1.10;
                prK=kiwi*1.20;
                *punterosum = *puntero1 + *puntero2 + *puntero3 + *puntero4 + *puntero5;
                *punterosum2= prM+prP+prU+prNA+prK;




                printf("********* Consumidor final *********\n\n");

                printf("Producto                Precio              Cantidad        Total  \n\n");

                printf("Mora                   $1.15 libra          :%.0f           :%.2f  \n\n",mora,prM);


                printf("Peras                 $1.50 libra           :%.0f           :%.2f\n\n",peras,prP);

                printf("Uvas                  $2.00 libra           :%.0f           :%.2f\n\n",uva,prU);

                printf("Naranjas               $1.10 libra)         :%.0f           :%.2f \n\n",naran,prNA);

                printf("Kiwi                   $1.20) libra         :%.0f           :%.2f\n\n",kiwi,prK);

                printf("total                                       :%.0f           :%.2f\n\n",suma,suma2);















                printf("Fin programa \n\n");




                break;

            default:

                printf("Opcion invalida \n");


                break;

        }


    }while (opcion != '3');







    return 0;
}
