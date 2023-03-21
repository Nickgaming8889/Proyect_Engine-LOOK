#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LONGITUD 6
#define INTENTOS 3

struct clients{
    int num_clt;
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[4];
    char tel[10];
};

struct clients n_o[100];

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
    printf("\nENGINE LOOK");

    system("pause");

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
char log_in() {

    char user[LONGITUD + 1];
    char password[LONGITUD + 1];
    int enter = 0, try = 0;

    do {
        system("cls");
        printf("Log In... \n");
        printf("Username: ");
        scanf("%s",user);
        printf("Password: ");
        scanf("%s",password);

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
char Registro_Clients() {
 
    int i, o, back = 1, end = 0;

    do
    {
        system("cls");
        fflush(stdin);
        for (i = back; i <= n_o&&end != 1; i++)
        {
            printf("Client Number: %i", n_o[i].num_clt);
            puts("\nClient Name: ");
            gets(n_o[i].name_clt);
            puts("Client Phone: ");
            gets(n_o[i].tel);
            puts("Vehicle Name: ");
            gets(n_o[i].mk);
            puts("Engine Serie: ");
            gets(n_o[i].nsm);
            puts("Year: ");
            gets(n_o[i].year);
            puts("license Plate: ");
            gets(n_o[i].plt);

            printf("\n\nDo you want to continue adding? Yes[1]/No[2] ");
            scanf("%d",&o);

            if (o == 1) {
                fflush(stdin);
            }
            else if (o == 2) {
                goto finish;
            }
        }
    } while (i != 101);

    if (i == 100) {
        printf("Client Limit is full now...");
    }
    
    finish:

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
                            Registro_Clients();

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
