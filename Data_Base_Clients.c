#include <stdio.h>
#include <stdlib.h>

struct clients{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    int year;
    char tel[10];
};

struct clients n_o[100];

int main() {

    int i, j, back = 0, end = 0;

    do
    {
        system("cls");
        fflush(stdin);
        for (i = back; i <= 100&&end != 1; i++)
        {
            puts("Client Name: ");
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

            printf("Do you want to continue adding? y/n");
            scanf("%d",&j);

            if (j = 'y'){
                /* code */
            }
            

        }
        
        
    } while (i != 101);
    

    return 0;
}