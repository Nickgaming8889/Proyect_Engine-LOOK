#include <stdio.h>
#include <stdlib.h>

int Registro() {
    int i = 0, j;
    char name_clt[80], mk[50], nsm[20], plt[10], year[4], tel[10];

    do{
        i++;
        system("cls");
        printf("No. Cliente %i\n", i);
        puts("Nombre del Cliente: ");
        gets(name_clt);
        puts("Número de telefono: ");
        gets(tel);
        puts("Modelo del Vehiculo: ");
        gets(mk);
        puts("Año del Vehiculo: ");
        gets(year);
        puts("No. de Serie del Motor: ");
        gets(nsm);
        puts("Placas: ");
        gets(plt);

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
    printf("\nModelo del Vehiculo: %s", mk);
    printf("\nPlacas de Vehiculo: %s\n\n", plt);

    system("pause");

    return 0;
}
