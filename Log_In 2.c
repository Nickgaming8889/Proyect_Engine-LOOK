#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LONGITUD 6
#define USER_NAME 1
#define INTENTOS 3

int main() {

    char user[LONGITUD + 1][USER_NAME];
    char password[LONGITUD + 1][USER_NAME];
    int enter = 0, try = 0; 

    do {
        system("cls");
        printf("Log In... \n");
        printf("Username: ");
        gets(user);
        printf("Password: ");
        gets(password);

        if (strcmp(user, "Nicolas") == 0 && strcmp(password, "12345") == 0){
            enter = 1;
            break;
        }
        else if (enter == 0) {
            printf("\n\tUsuario y/o clave son incorrectos\n");
            try++;
            getchar();
        }
        
    }while (try < INTENTOS && enter == 0);

    if (enter == 1) {
        printf("\nBienvenido al Sistema...");
    }
    else {
        printf("\nLimite Excedido...");
    }

    return 0;
}