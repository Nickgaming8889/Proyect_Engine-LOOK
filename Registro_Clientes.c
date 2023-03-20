#include <stdio.h>
#include <stdlib.h>

struct clients{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[4];
    char tel[10];
};

struct clients n_o[100];

int main() {

    int i, j, back = 1, end = 0;

    do
    {
        system("cls");
        fflush(stdin);
        for (i = back; i <= 100&&end != 1; i++)
        {
            printf("Client Number: %d", i);
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
            scanf("%d",&j);

            if (j == 1) {
                fflush(stdin);
            }
            else if (j == 2) {
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