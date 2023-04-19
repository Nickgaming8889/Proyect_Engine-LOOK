#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LONGITUD 6
#define INTENTOS 3
#define NUM_CLT 100

//Estructuras...
struct Clients{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[4];
    char phone[11];
};

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

    char user[LONGITUD + 1];
    char password[LONGITUD + 1];
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

//Funciones para el Registro y Baja...
int registro(struct Clients newClient, struct Clients n_o[], int *num_clt) {
    if (*num_clt >= NUM_CLT) {
        printf("\nExceeded Limit...");
    }
    else {
        n_o[*num_clt] = newClient;
        (*num_clt)++;
        printf("\nSuccessfully Register...");
    }
    return 0;
}

int delete(int clientNum, struct Clients n_o[], int *num_clt) {
    if (clientNum < 0 || clientNum >= *num_clt) {
        printf("Invalid Client Number...");
    }
    else {
        for (int i = clientNum; i < *num_clt; i++) {
            n_o[i] = n_o[i + 1];   
        }
        (*num_clt)--;
        printf("The user has been delete...");
    }
    return 0;
}

char view(struct Clients user){
    printf("\n\nClient Name: %s\n", user.name_clt);
    printf("Phone: %s\n", user.phone);
    printf("Car: %s\n", user.mk);
    printf("Year: %s\n", user.year);
    printf("License Plates: %s\n", user.plt);
    printf("Series Number: %s\n", user.nsm);
    
    return 0;
}

int Cost() {

    struct Clients n_o[NUM_CLT];

    int clientNum, num_clt = 0;

    printf("\nClients Search...\n");
    printf("Enter the client number (%d) (EXIT[-1]): ", num_clt-1);
    scanf("%i",&clientNum);

    if (clientNum >= 0 && clientNum < num_clt) {
        printf("Client %d:\n", clientNum);
        view(n_o[clientNum]);
    }
    else if (clientNum != -1) {
        printf("Invalid Client Number. \n");
    }
    
    system("pause");
}

//Función Registro...
int Registro() {
    struct Clients n_o[NUM_CLT];

    int op, num_clt = 0, i = 0;
    char buffer[100];

    struct Clients newClient;

    do
    {
        system("cls");
        printf("\n1. Register Client.");
        printf("\n2. Delete Client.");
        printf("\n3. Search Client.");
        printf("\n4. Exit");
        printf("\n\nWhat do you want to do? ");
        
        if (scanf("%d", &op) != 1) {
            printf("Invalid option, please put a number... ");
            fgets(buffer, sizeof(buffer), stdin);
            system("pause");
            continue;
        }

        switch (op) {
            case 1: {
                system("cls");

                printf("Client Name: ");
                scanf("%s", newClient.name_clt);
                printf("Client Phone: ");
                fflush(stdin);
                scanf("%s", newClient.phone);
                printf("Vehicle: ");
                scanf("%s", newClient.mk);
                printf("Year: ");
                scanf("%s", newClient.year);
                printf("Engine Series Number: ");
                scanf("%s", newClient.nsm);
                printf("License Plates: ");
                scanf("%s", newClient.plt);
                fflush(stdin);

                registro(newClient, n_o, &num_clt);

                printf("\n\nDo you want to continue adding? YES[1]/NO[2]: ");
                scanf("%i",&i);
                break;
            }
            case 2: {
                int clientNum;
                printf("Enter the client number (%d): ", num_clt -1);
                scanf("%d",&clientNum);
                fflush(stdin);

                delete(clientNum, n_o, &num_clt);
                break;
            }
            case 3: {
                int clientNum;

                printf("\nClients Search...\n");
                printf("Enter the client number (%d) (EXIT[-1]): ", num_clt-1);
                scanf("%i",&clientNum);

                if (clientNum >= 0 && clientNum < num_clt) {
                    printf("Client %d:\n", clientNum);
                    view(n_o[clientNum]);
                }
                else if (clientNum != -1) {
                    printf("Invalid Client Number. \n");
                }

                system("pause");
                break;
            }
        }
    } while (op != 4);

    return 0;
}

int main() {

    logo();

    load_page();

    fflush(stdin);
    log_in();

    int op;
    char buffer[100];

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

        if (scanf("%d", &op) != 1) {
            printf("Invalid option, please put a number... \n");
            fgets(buffer, sizeof(buffer), stdin);
            system("pause");
            continue;
        }

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
                    
                    if (scanf("%d", &op) != 1) {
                        printf("Invalid option, please put a number... \n");
                        fgets(buffer, sizeof(buffer), stdin);
                        system("pause");
                    }
                    //Caso según la opción elegida...
                    switch (op) {
                    case 1:
                        system("cls");
                        printf("\nEstas en Registro y Baja de Cliente...\n");

                            fflush(stdin);
                            Registro();

                        break;
                    case 2:
                        system("cls");
                        printf("\nEstas en Cotizacion de Reparacion...\n");

                            fflush(stdin);
                        break; 
                    case 3:
                        system("cls");
                        printf("\nEstas en Proceso de Trabajo...\n");
                        break;
                    case 4:
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

                    if (scanf("%d", &op) != 1) {
                        printf("Invalid option, please put a number... \n");
                        fgets(buffer, sizeof(buffer), stdin);
                        system("pause");
                    }
                    
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