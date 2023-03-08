#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, j;
    char name_clt[80], mk[50];

    do{
        i++;
        system("cls");
        printf("No. Cliente %i\n", i);
        puts("Nombre del Cliente: ");
        gets(name_clt);
        puts("Modelo del Vehiculo: ");
        gets(mk);

        printf("1.Salir.");
        printf("\nDeseas salir? ");
        scanf("%i", &j);

        if (j == 1) {
            goto finish;
        }
        else {
            fflush(stdin);
        }

    } while (i <= 100);

    finish:

    printf("\n\nNo. Cliente: %i", i);
    printf("\nNombre del Cliente: %s", name_clt);
    printf("\nModelo del Vehiculo: %s\n\n", mk);

    system("pause");

    return 0;
}