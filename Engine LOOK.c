#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LONGITUD 6
#define USER_NAME 1
#define INTENTOS 3

//GOTOXY
void gotoxy(int x,int y){

    HANDLE Ventana;
    COORD Coordenates;
    Ventana = GetStdHandle(STD_OUTPUT_HANDLE);

    Coordenates.X = x;
    Coordenates.Y = y;

    SetConsoleCursorPosition(Ventana,Coordenates);
}

//Función Logo...
int logo(){
    
    system("cls");
    gotoxy(42,2);
    printf("*****");
    gotoxy(40,3);
    printf("***   ***");
    gotoxy(39,4);
    printf("**   X   **");
    gotoxy(40,5);
    printf("***   ***");
    gotoxy(42,6);
    printf("*******");
    gotoxy(47,7);
    printf("***");
    gotoxy(48,8);
    printf("***");
    gotoxy(49,9);
    printf("***");
    gotoxy(40,12);
    printf("ENGINE LOOK");

    getch();

    return 0;
}

//Función Load Page...
int load_page() {

    system("cls");
    gotoxy(40,3);
    printf("Welcome to Engine LOOK");
    gotoxy(43,4);
    printf("Loading Program...");
    gotoxy(31,6);
    printf("Created by: Nicholas Caceres Version 1.23");

    return 0;
}

//Función Log_In...
int log_in() {

    char user[LONGITUD + 1][USER_NAME];
    char password[LONGITUD + 1][USER_NAME];
    int enter = 0, try = 0; 

    do {
        system("cls");
        printf("Log In... \n");
        printf("Username: ");
        scanf("%s", &user);
        printf("Password: ");
        scanf("%s", &password);

        if (strcmp(user, "Nicolas") == 0 && strcmp(password, "12345") == 0){
            enter = 1;
            break;
        }
        else if (enter == 0) {
            printf("\n\tUsuario y/o clave son incorrectos\n");
            try++;
            system("pause");
            getchar();
        }
        
    }while (try < INTENTOS && enter == 0);

    if (enter == 1) {
        printf("\nBienvenido al Sistema...");
    }
    else {
        printf("\nLimite Excedido...");
    }

    return 0;
}

//Función Registro...
int Registro() {
    int i = 0, j;
    char name_clt[80], mk[50], nsm[20], plt[12], year[4];

    do{
        i++;
        system("cls");
        printf("No. Cliente %i\n", i);
        puts("Nombre del Cliente: ");
        gets(name_clt);
        puts("Modelo del Vehiculo: ");
        gets(mk);
        puts("Año del Vehiculo");
        gets(year);
        puts("No. de Serie del Motor: ");
        gets(nsm);
        puts("Placas: ");
        gets(plt);

        printf("1.Salir.");
        printf("\nDeseas salir? ");
        scanf("%i", &j);

        if (j == 1) {
            goto finish;
        }
        else {
            fflush(stdin);
        }

    } while (i <= 100);

    finish:

    printf("\n\nNo. Cliente: %i", i);
    printf("\nNombre del Cliente: %s", name_clt);
    printf("\nModelo del Vehiculo: %s", mk);
    printf("\nPlacas de Vehiculo: %s\n\n", plt);

    system("pause");

    return 0;
}

int main() {

    fflush(stdin);
    logo();

    fflush(stdin);
    load_page();

    fflush(stdin);
    log_in();

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
            system("cls");
            printf("\nEstas en Administracion.\n");
                do
                {
                    printf("\n1. Registro del cliente.");
                    printf("\n2. Baja de cliente.");
                    printf("\n3. Cotizacion de reparacion.");
                    printf("\n4. Proceso de Trabajo.");
                    printf("\n5. Volver al menu principal.");
                    
                    //Solicitar dato de entrada al area requerida...
                    printf("\n\nSeleccione la opcion que necesite: ");
                    scanf("%i", &op);
                    
                    //Caso según la opción elegida...
                    switch (op) {
                    case 1:
                        system("cls");
                        printf("\nEstas en Registro de Cliente...\n");

                            fflush(stdin);
                            Registro();

                        break;
                    case 2:
                        system("cls");
                        printf("\nEstas en Baja de Cliente...\n");
                        break;
                    case 3:
                        system("cls");
                        printf("\nEstas en Cotizacion de Reparacion...\n");
                        break;
                    case 4:
                        system("cls");
                        printf("\nEstas en Proceso de Trabajo...\n");
                        break;
                    case 5:
                        system("cls");
                        goto main_menu;
                        break;
                    default:
                        printf("\nNumero no valido, intente nuevamente...\n");
                        break;
                    }

                } while (op != 5);
                
            break;
        case 2:
            system("cls");
            printf("\nEstas en Almacen y Compras.\n");
                do
                {
                    printf("\n1. Almacen.");
                    printf("\n2. Comprar piezas.");
                    printf("\n3. Volver al menu principal.");

                    //Solicitar dato de entrada al area requerida...
                    printf("\n\nSelecione la opcion que necesite: ");
                    scanf("%i", &op);
                    
                    //Caso según la opción elegida...
                    switch (op) {
                    case 1:
                        system("cls");
                        printf("\nEstas en el Almacen...\n");
                        break;
                    case 2:
                        system("cls");
                        printf("\nEstas en Compra de Piezas...\n");
                        break;
                    case 3:
                        system("cls");
                        goto main_menu;
                        break;
                    default:
                        printf("\nNumero no valido, intente nuevamente...\n");
                        break;
                    }
                } while (op != 3);

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