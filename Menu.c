#include <stdio.h>
#include <stdlib.h>

int main() {

    int op;

    do
    {
        //Secciones del menu principal...
        printf("\nBienvenido el Menu...");
        printf("\n\n1. Administracion.");
        printf("\n2. Almacen y Compras.");
        printf("\n3. Salir del Programa.");

        //Solicitar dato de entrada...
        printf("\n\nSeleccione el numero del submenu.. ");
        scanf("%i", &op);

        switch (op) {
        case 1:
            printf("\nEstas en Administracion.");
            break;
        case 2:
            printf("\nEstas en Almacen y Compras.");
            break;
        case 3:
            printf("\nHaz salido del programa.");
            break;
        default:
            break;
        }
    } while (op != 3);
    

    return 0;
}


