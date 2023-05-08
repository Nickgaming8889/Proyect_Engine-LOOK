#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CLT 100
#define IVA 0.15

typedef struct {
    float stdpiston_nissan;
    float limitstd_nissan;
    float toten;
    float totwenty;
    float tothirty;
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
}RorN;

typedef struct {
    float recti_price;
}Rect;

typedef struct {
    char wash[10];
    char larges[10];
    char rect[10];
    char deliver[10];
}Process;

typedef struct{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[20];
    char phone[20];
    RorN var;
    Rect price;
    Process works;
}Clients;

typedef struct {
    int id;
    char repair[50];
    float cost_repair;
    int time;
    float p_Hrs;
}Repairs;

int registro( Clients newClient, Clients n_o[], int *num_clt) {
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
    printf("Phone: %s\n\n", user.phone);
    printf("Car: %s\n", user.mk);
    printf("Year: %s\n\n", user.year);
    printf("License Plates: %s\n\n", user.plt);
    printf("Series Number: %s\n\n", user.nsm);
    
    return 0;
}

char saveprogress(Clients *user);

float variables(Clients *engine) {
    engine->var.stdpiston_nissan = 80.465;
    engine->var.limitstd_nissan = 80.515;
    engine->var.toten = 80.565;
    engine->var.totwenty = 80.665;
    engine->var.tothirty = 80.765;
    return 0;
}

float rect_price(Clients *price) {
    price->price.recti_price = 2000.00;
    return 0;
}

float recty(Clients *engine) {
    int ret, num_piston;
    char buffer[100];

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
            scanf("%f %f", &engine->var.piston_1T, &engine->var.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_2T, &engine->var.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_3T, &engine->var.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_4T, &engine->var.piston_4L);

            float max1 = fmax(engine->var.piston_1T, fmax(engine->var.piston_2T, fmax(engine->var.piston_3T, engine->var.piston_4T)));
            float max2 = fmax(engine->var.piston_1L, fmax(engine->var.piston_2L, fmax(engine->var.piston_3L, engine->var.piston_4L)));
            float mmax = fmax(max1, max2);

            printf("%3f\n", mmax);

            if (mmax > engine->var.stdpiston_nissan && mmax < engine->var.limitstd_nissan) {
                printf("By the moment it don need to be rectify");
                
            }
            else if (mmax > engine->var.limitstd_nissan && mmax < engine->var.toten) {
                printf("Rectification to 0.10mm.");
                
            }
            else if (mmax > engine->var.toten && mmax < engine->var.totwenty) {
                printf("Rectification to 0.20mm.");
                
            }
            else if (mmax > engine->var.totwenty && mmax < engine->var.tothirty) {
                printf("Rectification to 0.30mm.");
                
            }else{
                 printf("Change pieces...");
            }

            break;
        }
        case 6: {
            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_1T, &engine->var.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_2T, &engine->var.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_3T, &engine->var.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_4T, &engine->var.piston_4L);

            printf("\nPiston 5 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_5T, &engine->var.piston_5L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_6T, &engine->var.piston_6L);

            float max1 = fmax(engine->var.piston_1T, fmax(engine->var.piston_2T, fmax(engine->var.piston_3T, fmax(engine->var.piston_4T, fmax(engine->var.piston_5T, engine->var.piston_6T)))));
            float max2 = fmax(engine->var.piston_1L, fmax(engine->var.piston_2L, fmax(engine->var.piston_3L, fmax(engine->var.piston_4L, fmax(engine->var.piston_5L, engine->var.piston_6L)))));
            float mmax = fmax(max1, max2);

            printf("%f", mmax);

            if (mmax > engine->var.stdpiston_nissan && mmax < engine->var.limitstd_nissan) {
                printf("By the moment it don need to be rectify");
                
            }
            if (mmax > engine->var.limitstd_nissan && mmax < engine->var.toten) {
                printf("Rectification to 0.10mm.");
                
            }
            if (mmax > engine->var.toten && mmax < engine->var.totwenty) {
                printf("Rectification to 0.20mm.");
                
            }
            if (mmax > engine->var.totwenty && mmax < engine->var.tothirty) {
                printf("Rectification to 0.30mm.");
            }
            break;
        }
        case 8: {
            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_1T, &engine->var.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_2T, &engine->var.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_3T, &engine->var.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_4T, &engine->var.piston_4L);

            printf("\nPiston 5 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_5T, &engine->var.piston_5L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_6T, &engine->var.piston_6L);

            printf("\nPiston 7 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_7T, &engine->var.piston_7L);

            printf("\nPiston 8 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_8T, &engine->var.piston_8L);

            float max1 = fmax(engine->var.piston_1T, fmax(engine->var.piston_2T, fmax(engine->var.piston_3T, fmax(engine->var.piston_4T, fmax(engine->var.piston_5T, fmax(engine->var.piston_6T, fmax(engine->var.piston_7T, engine->var.piston_8T)))))));
            float max2 = fmax(engine->var.piston_1L, fmax(engine->var.piston_2L, fmax(engine->var.piston_3L, fmax(engine->var.piston_4L, fmax(engine->var.piston_5L, fmax(engine->var.piston_6L, fmax(engine->var.piston_7L, engine->var.piston_8L)))))));
            float mmax = fmax(max1, max2);

            printf("%f", mmax);

            if (mmax >= engine->var.stdpiston_nissan && mmax <= engine->var.limitstd_nissan) {
                printf("By the moment it don need to be rectify");
                
            }
            if (mmax > engine->var.limitstd_nissan && mmax < engine->var.toten) {
                printf("Rectification to 0.10mm.");
                
            }
            if (mmax > engine->var.toten && mmax < engine->var.totwenty) {
                printf("Rectification to 0.20mm.");
                
            }
            if (mmax > engine->var.totwenty && mmax < engine->var.tothirty) {
                printf("Rectification to 0.30mm.");
                
            }
            break;
        }
    }

    return 0;
}

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

    recty(user);

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

char saveprogress(Clients *user) {
    FILE *ft = fopen ("progress.txt", "a");
    if (ft != NULL) {
        fprintf (ft, "Client: %s Ready_Washed Y[1]/N[2]: %s Ready_TakeLarges Y[1]/N[2]: %s Recti: %s Deliver: %s\n", user->name_clt, user->works.wash, user->works.larges, user->works.rect, user->works.deliver);
        fclose(ft);
    }
    return 0;
}

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
            fprintf(ticket, "\tID Reparacion: %d  Name: %s\n\n", id, repairs[j].repair);
            break;
        }
    }

    fprintf(ticket, "Client Name: %s\n", user.name_clt);
    fprintf(ticket, "Horas trabajadas: %d\n", hrs);
    fprintf(ticket, "Subtotal: %.2f\n", total / 1.15);
    fprintf(ticket, "IVA: %.2f\n", total * 0.15);
    fprintf(ticket, "Total: %.2f\n", total);

    fclose(file);
    fclose(ticket);

    return 0;
}

int main() {
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
        printf("\n6. Get back to principal menu.");
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