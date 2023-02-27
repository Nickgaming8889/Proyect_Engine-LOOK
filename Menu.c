#include <stdio.h>
#include <stdlib.h>

int main() {

    int op;

    do
    {
        //Secciones del menu principal...
        main_menu:
        system("cls");
        printf("\nBienvenido el Menu...");
        printf("\n\n1. Administracion.");
        printf("\n2. Almacen y Compras.");
        printf("\n3. Salir del Programa.");

        //Solicitar dato de entradaa submenu...
        printf("\n\nSeleccione el numero del submenu.. ");
        scanf("%i", &op);

        //Redireccion al submenu...
        switch (op) {
        case 1:
            //Admi:
            system("cls");
            printf("\nEstas en Administracion.");
                do
                {
                    printf("\n1. Registro del cliente.");
                    printf("\n2. Baja de cliente.");
                    printf("\n3. Cotizacion de reparacion.");
                    printf("\n4. Volver al menu principal.");
                    
                    //Solicitar dato de entrada al area requerida...
                    printf("\n\nSeleccione la opcion que necesite: ");
                    scanf("%i", &op);

                    switch (op) {
                    case 1:
                        printf("\nEstas en Registro de Cliente...\n");
                        break;
                    case 2:
                        printf("\nEstas en Baja de Cliente...\n");
                        break;
                    case 3:
                        printf("\nEstas en Cotizacion de Reparacion...\n");
                        break;
                    case 4:
                        goto main_menu;
                        break;
                    default:
                        break;
                    }

                } while (op != 4);
                
            break;
        case 2:
            printf("\nEstas en Almacen y Compras.");
            break;
        case 3:
            printf("\nHaz salido del programa.");
            break;
        default:
            printf("\nEl numero no valido, intente nuevamente");
            break;
        }
    } while (op != 3);
    

    return 0;
}


