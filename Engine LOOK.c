#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LONGITUD 6
#define INTENTOS 3
#define NUM_CLT 100

//Estructuras...
typedef struct {
    char wash[10];
    char larges[10];
}Process;

typedef struct{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[20];
    char phone[20];
    Process works;
}Clients;

typedef struct{
    int id;
    char name[50];
    int num_part;
    float price;
}Article;

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
int registro(Clients newClient, Clients n_o[], int *num_clt) {
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

int delete(int clientNum, Clients n_o[], int *num_clt) {
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

char view(Clients user){
    printf("\n\nClient Name: %s\n", user.name_clt);
    printf("Phone: %s\n", user.phone);
    printf("Car: %s\n", user.mk);
    printf("Year: %s\n", user.year);
    printf("License Plates: %s\n", user.plt);
    printf("Series Number: %s\n", user.nsm);
    
    return 0;
}

//Función Cotización...
int Cost() {

    Clients n_o[NUM_CLT];

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

//Función Progreso...
char process(Clients *user) {

    printf("\nThe engine is already clean? Y(1)/N(2) ");
    scanf("%s", user->works.wash);
    printf("Larges are already taked? Y(1)/N(2) ");
    scanf("%s", user->works.larges);

    return 0;
}

//Función Registro...
int Registro() {
    Clients n_o[NUM_CLT];
    int ret;

    int op, num_clt = 0, i = 0;
    char buffer[100]; 

    Clients newClient;

    do
    {
        //system("cls");
        printf("\n1. Register Client.");
        printf("\n2. Delete Client.");
        printf("\n3. Search Client.");
        printf("\n4. Progress Work.");
        printf("\n5. Repair Cost.");
        printf("\n6. Exit.");
        printf("\n\nWhat do you want to do? ");
        
        ret = scanf("%d", &op);
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid option, please put a number... ");
            fgets(buffer, sizeof(buffer), stdin);
            continue;
        }

        switch (op) {
            case 1: {
                system("cls");

                printf("Client Name: ");
                fgets(newClient.name_clt, sizeof(newClient.name_clt), stdin);
                printf("Client Phone: ");
                scanf("%s", newClient.phone);
                while (getchar() != '\n');
                //printf("Phone: %s\n", newClient.phone);
                printf("Vehicle: ");
                fgets(newClient.mk, sizeof(newClient.mk), stdin);
                printf("Year: ");
                scanf("%s", newClient.year);
                printf("Engine Series Number: ");
                scanf("%s", newClient.nsm);
                printf("License Plates: ");
                scanf("%s", newClient.plt);

                registro(newClient, n_o, &num_clt);

                printf("\n\nDo you want to continue adding? YES[1]/NO[2]: ");
                scanf("%i",&i);
                while (getchar() != '\n');
                break;
            }
            case 2: {
                int clientNum;
                printf("Enter the client number (%d): ", num_clt -1);
                scanf("%d",&clientNum);
                while (getchar() != '\n');

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
            case 4: {
                int clientNum;

                printf("\nClients Search...\n");
                printf("Enter the client number (%d) (EXIT[-1]): ", num_clt-1);
                scanf("%i",&clientNum);

                if (clientNum >= 0 && clientNum < num_clt) {
                    printf("Client %d:\n", clientNum);
                    process(&n_o[clientNum]);


                }
                else if (clientNum != -1) {
                    printf("Invalid Client Number. \n");
                }

                break;
            }
            case 5: { 
                
                break;
            }
            default: 
                printf("Invalid option, try again...");
                break;
        }
    } while (op != 6);

    return 0;
}

//Lista de precios y articulos...
int Prices() {
    
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    Article articles[50];
    int i = 0;

    while (!feof(file)) {
        fscanf(file, "%d %s %f", &articles[i].id, articles[i].name, &articles[i].price);
        i++;
    }

    fclose(file);

    printf("Read %d articles:\n", i);

    for (int j = 0; j < i; j++) {
        printf("Article %d:\n", j+1);
        printf("ID: %d\n", articles[j].id);
        printf("Name: %s\n", articles[j].name);
        printf("Price: %.2f\n", articles[j].price);
    }

    return 0;
}

int shop() {
    
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    Article articles[50];
    int i = 0;

    while (!feof(file)) {
        fscanf(file, "%d %s %d %f", &articles[i].id, articles[i].name, &articles[i].num_part, &articles[i].price);
        i++;
    }

    fclose(file);

    printf("Read %d articles:\n", i);

    for (int j = 0; j < i; j++) {
        printf("Article %d:\n", j+1);
        printf("ID: %d  ", articles[j].id);
        printf("Name: %s  ", articles[j].name);
        printf("Parts: %d  ", articles[j].num_part);
        printf("Price: %.2f\n", articles[j].price);
    }

    int article_id;
    printf("For which one you want to buy some parts: ");    
    scanf("%d", &article_id);

    for (int j = 0; j < i; j++) {
        if (articles[j].id == article_id) {
            printf("Article %d:\n", j+1);
            printf("ID: %d  ", articles[j].id);
            printf("Name: %s  ", articles[j].name);
            printf("Parts: %d  ", articles[j].num_part);
            printf("Price: %.2f\n", articles[j].price);
            
            int new_quantity;
            printf("Enter new quantity for article %d (%s): ", article_id, articles[j].name);
            scanf("%d", &new_quantity);

            articles[j].num_part += new_quantity;
            float cost = articles[j].price * new_quantity;

            printf("New quantity for article %d (%s): %d Cost: %2f\n", article_id, articles[j].name, articles[j].num_part, cost);

            break;
        }
        if (j == i-1) {
            printf("Article not found\n");
        }
    }

    return 0;
}

int main() {

    logo();

    load_page();

    while (getchar() != '\n');
    log_in();

    int op, ret;
    char buffer[100];

    do
    {
        //Secciones del menu principal...
        main_menu:
        system("cls");
        printf("\nWelcome to Menu...");
        printf("\n\n1. Administration.");
        printf("\n2. Store and Shopping.");
        printf("\n3. Exit Program.");

        //Solicitar dato de entradaa submenu...
        printf("\n\nChoose the option you need.. ");

        ret = scanf("%d", &op);
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid option, please put a number... ");
            fgets(buffer, sizeof(buffer), stdin);
            continue;
        }

        //Redireccion al submenu...
        switch (op) {
        case 1:
            system("cls");
            printf("\nAdministration.\n");
                do
                {
                    printf("\n1. Regist, Remove Client, Progress and Repair Price.");
                    printf("\n2. Go back principal menu.");
                    
                    //Solicitar dato de entrada al area requerida...
                    printf("\n\nSeleccione la opcion que necesite: ");
                    
                    ret = scanf("%d", &op);
                    while (getchar() != '\n');
                    if (ret != 1) {
                        printf("Invalid option, please put a number... ");
                        fgets(buffer, sizeof(buffer), stdin);
                        continue;
                    }
                    //Caso según la opción elegida...
                    switch (op) {
                    case 1:
                        system("cls");
                        printf("\nEstas en Regist, Remove Client, Progress and Repair Price.\n");

                            //while (getchar() != '\n');
                            Registro();

                        break; 
                    case 2:
                        system("cls");
                        goto main_menu;
                        break;
                    default:
                        printf("\nInvalid number, try again...\n");
                        break;
                    }

                } while (op != 2);
                
            break;
        case 2:
            system("cls");
            printf("\nStore and Shopping.\n");
                do
                {
                    printf("\n1. Store.");
                    printf("\n2. Part Shopping.");
                    printf("\n3. Go back to principal menu.");

                    //Solicitar dato de entrada al area requerida...
                    printf("\n\nChoose the option you need: ");

                    ret = scanf("%d", &op);
                    while (getchar() != '\n');
                    if (ret != 1) {
                        printf("Invalid option, please put a number... ");
                        fgets(buffer, sizeof(buffer), stdin);
                        continue;
                    }   
                    
                    //Caso según la opción elegida...
                    switch (op) {
                    case 1:
                        system("cls");
                        printf("\nStore.\n");

                            Prices();
                            
                        break;
                    case 2:
                        system("cls");
                        printf("\nPart Shopping.\n");
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