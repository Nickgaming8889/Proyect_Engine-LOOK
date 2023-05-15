#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define LONGITUD 6
#define INTENTOS 3
#define NUM_CLT 100
#define IVA 0.15

//Estructuras...
typedef struct {
    char wash[10];
    char larges[10];
    char rect[10];
    char deliver[10];
}Process;

typedef struct {
    float piston_1T;
    float piston_1L;
    float piston_2T;
    float piston_2L;
    float piston_3T;
    float piston_3L;
    float piston_4T;
    float piston_4L;
    float piston_5T;
    float piston_5L;
    float piston_6T;
    float piston_6L;
    float piston_7T;
    float piston_7L;
    float piston_8T;
    float piston_8L;
}Piston;

typedef struct{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[20];
    char phone[20];
    Process works;
    Piston eng;
}Clients;

typedef struct{
    int id;
    char name[50];
    int num_part;
    float price;
}Article;

typedef struct {
    int id;
    char repair[50];
    float cost_repair;
    int time;
    float p_Hrs;
}Repairs;

typedef struct {
    float stdpiston_nissan;
    float limitstd_nissan;
    float toten;
    float totwenty;
    float tothirty;
}RorN;

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

int Timer() {
    int total = 100;
    int i;

    for (i = 1; i <= total; i++) {
        gotoxy(32,8);
        printf("Progress [%-20s] %d%%\r", "====================", i);
        fflush(stdout);
        Sleep(200);
    }

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
    printf("Created by: Nicholas Caceres Version 1.23\n\n\t");

    Timer();

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

//Funcion para guardar el cliente...
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

//Funcion para eliminar a un cliente...
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

//Funcion para ver los datos del cliente...
char view(Clients user){
    printf("\n\nClient Name: %s\n", user.name_clt);
    printf("Phone: %s\n\n", user.phone);
    printf("Car: %s\n", user.mk);
    printf("Year: %s\n\n", user.year);
    printf("License Plates: %s\n\n", user.plt);
    printf("Series Number: %s\n\n", user.nsm);
    
    return 0;
}

RorN var;

float variables() {

    var.stdpiston_nissan = 80.465;
    var.limitstd_nissan = 80.515;
    var.toten = 80.565;
    var.totwenty = 80.665;
    var.tothirty = 80.765;    
    return 0;
}

Clients engine;

int recti() {
    int ret, num_piston;
    char buffer[100];

    variables();

    printf("Choose how much pistons have the engine (4 to 8): ");
    ret = scanf("%d", &num_piston);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("\nInvalid option, enter a number between 4 to 8: ");
        fgets(buffer, sizeof(buffer), stdin);
    }

    switch (num_piston) {
        case 4: {

            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_1T, &engine.eng.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_2T, &engine.eng.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_3T, &engine.eng.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_4T, &engine.eng.piston_4L);

            float max1 = fmax(engine.eng.piston_1T, fmax(engine.eng.piston_2T, fmax(engine.eng.piston_3T, engine.eng.piston_4T)));
            float max2 = fmax(engine.eng.piston_1L, fmax(engine.eng.piston_2L, fmax(engine.eng.piston_3L, engine.eng.piston_4L)));
            float mmax = fmax(max1, max2);

            printf("%.3f", mmax);

            if (mmax >= var.stdpiston_nissan && mmax <= var.limitstd_nissan) {
            printf("\nBy the moment it doesn't need to be rectified.");
            }
            else if (mmax >= var.limitstd_nissan && mmax <= var.toten) {
                printf("\nRectification to 0.10mm.");
            }
            else if (mmax >= var.toten && mmax <= var.totwenty) {
                printf("\nRectification to 0.20mm.");
            }
            else if (mmax >= var.totwenty && mmax <= var.tothirty) {
                printf("\nRectification to 0.30mm.");
            }
            else {
                printf("\nIt's better to change pieces and recover monoblock glass...");
            }
            break;
        }
        case 6: {
            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_1T, &engine.eng.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_2T, &engine.eng.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_3T, &engine.eng.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_4T, &engine.eng.piston_4L);

            printf("\nPiston 5 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_5T, &engine.eng.piston_5L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_6T, &engine.eng.piston_6L);

            float max1 = fmax(engine.eng.piston_1T, fmax(engine.eng.piston_2T, fmax(engine.eng.piston_3T, fmax(engine.eng.piston_4T, fmax(engine.eng.piston_5T, engine.eng.piston_6T)))));
            float max2 = fmax(engine.eng.piston_1L, fmax(engine.eng.piston_2L, fmax(engine.eng.piston_3L, fmax(engine.eng.piston_4L, fmax(engine.eng.piston_5L, engine.eng.piston_6L)))));
            float mmax = fmax(max1, max2);

            printf("%.3f", mmax);

            if (mmax >= var.stdpiston_nissan || mmax <= var.limitstd_nissan) {
            printf("\nBy the moment it doesn't need to be rectified.");
            }
            else if (mmax >= var.limitstd_nissan && mmax <= var.toten) {
                printf("\nRectification to 0.10mm.");
            }
            else if (mmax > var.toten && mmax <= var.totwenty) {
                printf("\nRectification to 0.20mm.");
            }
            else if (mmax > var.totwenty && mmax <= var.tothirty) {
                printf("\nRectification to 0.30mm.");
            }
            else {
                printf("\nIt's better to change pieces and recover monoblock glass...");
            }
            break;
        }
        case 8: {
            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_1T, &engine.eng.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_2T, &engine.eng.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_3T, &engine.eng.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_4T, &engine.eng.piston_4L);

            printf("\nPiston 5 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_5T, &engine.eng.piston_5L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_6T, &engine.eng.piston_6L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_7T, &engine.eng.piston_7L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine.eng.piston_8T, &engine.eng.piston_8L);

            float max1 = fmax(engine.eng.piston_1T, fmax(engine.eng.piston_2T, fmax(engine.eng.piston_3T, fmax(engine.eng.piston_4T, fmax(engine.eng.piston_5T, fmax(engine.eng.piston_6T, fmax(engine.eng.piston_7T, engine.eng.piston_8T)))))));
            float max2 = fmax(engine.eng.piston_1L, fmax(engine.eng.piston_2L, fmax(engine.eng.piston_3L, fmax(engine.eng.piston_4L, fmax(engine.eng.piston_5L, fmax(engine.eng.piston_6L, fmax(engine.eng.piston_7L, engine.eng.piston_8L)))))));
            float mmax = fmax(max1, max2);

            printf("%f", mmax);

            if (mmax >= var.stdpiston_nissan || mmax <= var.limitstd_nissan) {
            printf("\nBy the moment it doesn't need to be rectified.");
            }
            else if (mmax >= var.limitstd_nissan && mmax <= var.toten) {
                printf("\nRectification to 0.10mm.");
            }
            else if (mmax > var.toten && mmax <= var.totwenty) {
                printf("\nRectification to 0.20mm.");
            }
            else if (mmax > var.totwenty && mmax <= var.tothirty) {
                printf("\nRectification to 0.30mm.");
            }
            else {
                printf("\nIt's better to change pieces and recover monoblock glass...");
            }
            break;
        }
    }
    return 0;
}

char saveprogress(Clients *user);

//Función Progreso...
char process(Clients *user) {
    int ret, o;
    char buffer[100];

    FILE *ft = fopen ("progress.txt", "r");
    if (ft == NULL) {
        char line[100];
        while (fgets(line, sizeof(line), ft)) {
            char *name = strtok(line, ",");
            if (strcmp(name, user->name_clt) == 0) {
                char *wash = strtok(NULL, ",");
                char *larges = strtok(NULL, ",");
                char *rect = strtok(NULL, ",");
                char *deliver = strtok(NULL, ",");
                strcpy(user->works.wash, wash);
                strcpy(user->works.larges, larges);
                strcpy(user->works.rect, rect);
                strcpy(user->works.deliver, deliver);
                break;
            }
        }
        fclose(ft);
    }

    printf("The engine is already clean? Y[1]/N[2] ");
    scanf("%s", user->works.wash);

    printf("\nDo you want to continue? Y[1]/N[2] ");
    ret = scanf("%d", &o);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
    }
    if (o == 1) {
        saveprogress(user);
    }
    if (o == 2) {
        saveprogress(user);
        return 0;
    }

    printf("\nLarges are already taked? Y[1]/N[2] ");
    scanf("%s", user->works.larges);

    recti();

    printf("\nDo you want to continue? Y[1]/N[2] ");
    ret = scanf("%d", &o);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
    }
    if (o == 1) {
        saveprogress(user);
    }
    if (o == 2) {
        saveprogress(user);
        return 0;
    }

    printf("\nRectification is already did it? Y[1]/N[2] ");
    scanf("%s", user->works.rect);

    printf("\nDo you want to continue? Y[1]/N[2] ");
    ret = scanf("%d", &o);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
    }
    if (o == 1) {
        saveprogress(user);
    }
    if (o == 2) {
        saveprogress(user);
        return 0;
    }

    printf("\nReady to deliver? Y[1]/N[2] ");
    scanf("%s", user->works.deliver);

    printf("\nDo you want to continue? Y[1]/N[2] ");
    ret = scanf("%d", &o);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
    }
    if (o == 1) {
        saveprogress(user);
    }
    if (o == 2) {
        saveprogress(user);
        return 0;
    }

    return 0;
}

//Esto guarda lo que se lleva en el proceso, al txt....
char saveprogress(Clients *user) {
    FILE *ft = fopen ("progress.txt", "a");
    if (ft != NULL) {
        fprintf (ft, "Client: %s Ready_Washed Y[1]/N[2]: %s Ready_TakeLarges Y[1]/N[2]: %s Ready_Recty: %s Ready_Deliver: %s\n", user->name_clt, user->works.wash, user->works.larges);
        fclose(ft);
    }

    return 0;
}

//Generacion del Ticket...
int cost(Clients user) {

    FILE *file = fopen("example2.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    Repairs repairs[50];
    int i = 0;

    while (!feof(file)) {
        fscanf(file, "%d %s %f %d %f", &repairs[i].id, repairs[i].repair, &repairs[i].cost_repair, &repairs[i].time, &repairs[i].p_Hrs);
        i++;
    }

    FILE *ticket = fopen("Ticker_Cotizacion.txt", "w");

    if (ticket == NULL) {
        printf("Error opening file.");
        return 1;
    }

    int id;
    printf("Ingrese el ID de la reparacion: ");
    scanf("%d", &id);

    float total = 0;
    int hrs;
    printf("Ingrese el tiempo en horas trabajadas: ");
    scanf("%d", &hrs);
    total += hrs * 172.87 * (1 + IVA);

    for (int j = 0; j < i; j++) {
        if (repairs[j].id == id) {
            total += repairs[j].cost_repair;
            repairs[j].time = hrs;
            repairs[j].p_Hrs = 172.87 * (1 + IVA);
            fprintf(ticket, "\tID Reparacion: %d  Reapair Name: %s\n\n", id, repairs[j].repair);
            break;
        }
    }

    fprintf(ticket, "\tClient Name: %s\n", user.name_clt);
    fprintf(ticket, "\tHoras trabajadas: %d\n", hrs);
    fprintf(ticket, "\tSubtotal: %.2f\n", total / 1.15);
    fprintf(ticket, "\tIVA: %.2f\n\n", total * 0.15);
    fprintf(ticket, "\t\tTotal: %.2f\n", total);

    fclose(file);
    fclose(ticket);

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
                printf("Repair Cost: ");
                int clientNum;

                printf("\nClients Search...\n");
                printf("Enter the client number (%d) (EXIT[-1]): ", num_clt-1);
                scanf("%i",&clientNum);

                if (clientNum >= 0 && clientNum < num_clt) {
                    printf("Client %d:\n", clientNum);
                    cost(n_o[clientNum]);


                }
                else if (clientNum != -1) {
                    printf("Invalid Client Number. \n");
                }

                break;
            }
        }
    } while (op != 6);

    return 0;
}

//Lista de precios y articulos...
int Prices() {
    int ret;
    char buffer[100];
    
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

    int o;

    do {

        printf("Read %d articles:\n", i);

        for (int j = 0; j < i; j++) {
            printf("ID: %d Name: %s Parts: %d Price: %.2f\n", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);
        }

        int article_id;
        printf("Enter article ID to search: ");
        ret = scanf("%d", &article_id);
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid option, please put a number... ");
            fgets(buffer, sizeof(buffer), stdin);
            //continue;
        }

        for (int j = 0; j < i; j++) {
            if (articles[j].id == article_id) {
                printf("Article %d:\n", j+1);
                printf("ID: %d Name: %s Parts: %d Price: %.2f\n", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);

                int new_quantity;
                printf("Enter new quantity for article %d (%s): ", article_id, articles[j].name);

                ret = scanf("%d", &new_quantity);
                while (getchar() != '\n');
                if (ret != 1) {
                    printf("Invalid option, please put a number... ");
                    fgets(buffer, sizeof(buffer), stdin);
                    //continue;
                }

                articles[j].num_part -= new_quantity;
                float cost = -new_quantity * articles[j].price;

                fseek(file, ftell(file)-sizeof(Article), SEEK_SET);
                fprintf(file, "%d %s %d %.2f", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);

                printf("New quatity for article %d (%s): %d Cost: %.2f", article_id, articles[j].name, articles[j].num_part, cost);

                printf("\n\nDo you want to continue taking articles? y(1)/n(2) ");
                ret = scanf("%d", &o);
                while (getchar() != '\n');
                if (ret != 1) {
                    printf("Invalid option, please put a number... ");
                    fgets(buffer, sizeof(buffer), stdin);
                    continue;
                }

                break;
            }
            if (j == i-1) {
                printf("Article not found\n");
            }
        }

    }while (o != 2);

    fclose(file);

    return 0;
}


//Compras...
int shop() {
    int ret;
    char buffer[100];
    
    FILE *file = fopen("example.txt", "r+");
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

    int o;

    do {
        printf("Read %d articles:\n", i);

        for (int j = 0; j < i; j++) {
            printf("Article %d:\n", j+1);
            printf("ID: %d Name: %s Parts: %d Price: %.2f\n", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);
        }

        int article_id;
        printf("Enter article ID to search: ");
        ret = scanf("%d", &article_id);
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid option, please put a number... ");
            fgets(buffer, sizeof(buffer), stdin);
            //continue;
        }

        for (int j = 0; j < i; j++) {
            if (articles[j].id == article_id) {
                printf("Article %d:\n", j+1);
                printf("ID: %d Name: %s Parts: %d Price: %.2f\n", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);

                int new_quantity;
                printf("Enter new quantity for article %d (%s): ", article_id, articles[j].name);
          
                ret = scanf("%d", &new_quantity);
                while (getchar() != '\n');
                if (ret != 1) {
                    printf("Invalid option, please put a number... ");
                    fgets(buffer, sizeof(buffer), stdin);
                    //continue;
                }

                articles[j].num_part += new_quantity;
                float cost = new_quantity * articles[j].price;

                fseek(file, ftell(file)-sizeof(Article), SEEK_SET);
                fprintf(file, "%d %s %d %.2f", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);

                printf("New quatity for article %d (%s): %d Cost: %.2f", article_id, articles[j].name, articles[j].num_part, cost);

                printf("\n\nDo you want to continue buying articles? y(1)/n(2) ");
                ret = scanf("%d", &o);
                while (getchar() != '\n');
                if (ret != 1) {
                    printf("Invalid option, please put a number... ");
                    fgets(buffer, sizeof(buffer), stdin);
                    continue;
                }

                break;
            }
            else if (j == i-1) {
                printf("\nArticle not found\n");
            }
        }
    } while (o != 2);

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