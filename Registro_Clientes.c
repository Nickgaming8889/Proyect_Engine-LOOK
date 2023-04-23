#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLT 100

struct Clients{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[4];
    char phone[11];
};

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

int cost(struct Clients usercost) {
    
}

int main() {
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