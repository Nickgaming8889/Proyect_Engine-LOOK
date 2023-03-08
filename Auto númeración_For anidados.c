#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    char num_clt, name_clt[80], mk[50];

    system("cls");
    for (i = 1; i <= 100; i++) {
        num_clt = i;
        printf("Num. Cliente %i\n", num_clt);
        for (j = 0; j <= i; j++) {
            puts("Nombre del Cliente: ");
            gets(name_clt);
            puts("Modelo del Vehiculo: ");
            gets(mk);
            break;
        }
        break;
    }

    printf("\nNumero de Cliente: %i", num_clt);
    printf("\nNombre del Cliente: %s", name_clt);
    printf("\nModelo del Vehiculo: %s", mk);


    return 0;
}
