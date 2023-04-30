#include <stdio.h>
#include <stdlib.h>

#define NUM_CLT 100

typedef struct{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[20];
    char phone[20];
    Process works;
}Clients;

typedef struct {
    char wash[10];
    char larges[10];

}Process;

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

char view(Clients user){

    printf("\n\nClient Name: %s\t", user.name_clt);
    printf("Car: %s\n", user.mk);
    printf("Year: %s\n\n", user.year);
    printf("License Plates: %s\n\n", user.plt);
    printf("Series Number: %s\n\n", user.nsm);

    return 0;
}

char process(Clients *user) {

    printf("The engine is already clean? Y(1)/N(2)");
    scanf("%s", user->works.wash);
    printf("Larges are already taked? Y(1)/N(2)");
    scanf("%s", user->works.larges);

    return 0;
}

int main() {
    Clients n_o[NUM_CLT];
    int clientNum, num_clt = 0, ret;
    char buffer[100];

    printf("\nClients Search...\n");
    printf("Enter the client number (%d) (EXIT[-1]): ", num_clt-1);
    
    ret = scanf("%i",&clientNum);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("Invalid option, please put a number... ");
        fgets(buffer, sizeof(buffer), stdin);
        //continue;
        //Quitar comentario en el programa final
    }

    if (clientNum >= 0 && clientNum < num_clt) {
        printf("Client %d:\n", clientNum);
        view(n_o[clientNum]);

        process(&n_o[clientNum]);
    }
    else if (clientNum != -1) {
        printf("Invalid Client Number. \n");
    }

    return 0;
}