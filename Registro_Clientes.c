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

char view(struct Clients user){
    printf("\n\nClient Name: %s\n", user.name_clt);
    printf("Phone: %s\n", user.phone);
    printf("Car: %s\n", user.mk);
    printf("Year: %s\n", user.year);
    printf("License Plates: %s\n", user.plt);
    
    return 0;
}

int main() {
    struct Clients n_o[NUM_CLT];

    int num_clt = 0, i = 0;

    struct Clients newClient;

    do
    {
        system("cls");

        printf("Client Name: ");
        scanf("%s", newClient.name_clt);
        printf("Client Email: ");
        scanf("%s", newClient.phone);
        printf("Vehicle: ");
        scanf("%s", newClient.mk);
        printf("Year: ");
        scanf("%s", newClient.year);
        printf("Engine Series Number: ");
        scanf("%s", newClient.nsm);
        printf("License Plates: ");
        scanf("%s", newClient.plt);

        registro(newClient, n_o, &num_clt);

        printf("Do you want to continue adding? YES[1]/NO[2]: ");
        scanf("%i",&i);

    } while (i != 2);
    
    int clientNum;

    printf("\nClients Search...\n");
    printf("Enter the user number (%d) (EXIT[-1]): ", num_clt-1);
    scanf("%i",&clientNum);

    if (clientNum >= 0 && clientNum < num_clt) {
        printf("Client %d:\n", clientNum);
        view(n_o[clientNum]);
    }
    else if (clientNum != -1) {
        printf("Invalid Client Number. \n");
    }
    

    return 0;
}