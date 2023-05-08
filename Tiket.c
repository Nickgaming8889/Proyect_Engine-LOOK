#include <stdio.h>
#include <stdlib.h>

#define IVA 0.15

typedef struct {
    int id;
    char repair[50];
    float cost_repair;
    int time;
    float p_Hrs;
}Repairs;

int main() {

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
            fprintf(ticket, "ID Reparacion: %d Name: %s\n", id, repairs[j].repair);
            break;
        }
    }

    fprintf(ticket, "Horas trabajadas: %d\n", hrs);
    fprintf(ticket, "Subtotal: %.2f\n", total / 1.15);
    fprintf(ticket, "IVA: %.2f\n", total * 0.15);
    fprintf(ticket, "Total: %.2f\n", total);

    fclose(file);
    fclose(ticket);

    return 0;
}
