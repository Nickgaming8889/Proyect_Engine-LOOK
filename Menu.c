#include <stdio.h>
#include <stdlib.h>

void main() {
    
    int opc, nsm, placa, year;
    char nv, mdl, name;

    do
    {
        system("cls");
        //Opciones de menu...
        printf("Bienvenido al Menu...\n");
        printf("\n1. Registro del Cliente y/o Vehiculo.");
        printf("\n2. Inspección y Estimación de Costo.");
        printf("\n3. Almacen.");
        printf("\n4. Progreso de Reparación.");
        //Pide la opción a elegir...
        printf("\nQue deseas hacer hoy?..");
        gets(opc);

        //Sección del switch (aqui ira cada caso)...
        switch (opc) {
        case 1:
            //Solicitar datos de cliente y el vehiculo...
            printf("Registro del Cliente y/o Vehiculo:");

            //Datos del Cliente...
            printf("Nombre del Cliente: ");
            gets(name);
            
            break;
        
        default:
            break;
        }
    } while ();
    

    return 0;
}
