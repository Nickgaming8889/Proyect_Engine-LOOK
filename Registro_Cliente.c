#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLT 100

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
                strcpy(user->works.wash, wash);
                strcpy(user->works.larges, larges);
                break;
            }
        }
        fclose(ft);
    }

    printf("The engine is already clean? Y[1]/N[2] ");
    scanf("%s", user->works.wash);

    printf("\n\nDo you want to continue? Y[1]/N[2] ");
    ret = scanf("%d", &o);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
    }
    if (o == 2) {
        saveprogress(user);
        return 0;
    }

    printf("Larges are already taked? Y[1]/N[2] ");
    scanf("%s", user->works.larges);

    printf("\n\nDo you want to continue? Y[1]/N[2] ");
    ret = scanf("%d", &o);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
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
        printf (ft, "%s %s %s\n", user->name_clt, user->works.wash, user->works.larges);
        fclose(ft);
    }

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
            /*case 5: { 
                
                break;
            }*/
        }
    } while (op != 6);

    return 0;
}