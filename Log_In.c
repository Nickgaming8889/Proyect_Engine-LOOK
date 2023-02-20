#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <windows.h>

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 7
#define MAX_INTENTOS 3

#define NUMERO_USUARIOS 2

void main() {
	char user[LONGITUD + 1];
	char password[LONGITUD + 1];
	int try = 0;
	int enter = 0;
	char caracter;
	int i = 0;
    int j = 0;

    char users[NUMERO_USUARIOS][LONGITUD + 1] = {"Nicolas", "Tadeo"};
    char passwords[NUMERO_USUARIOS][LONGITUD + 1] = {"12345", "54321"};
	
	do {
		i = 0;
		system("cls");
        gotoxy(40, 2);
		printf("Log In... ");
        gotoxy(38, 4);
		printf("User: ");
		gets(user);
        gotoxy(38,5);
		printf("Password: ");
		while (caracter = getch()) {
			if (caracter == TECLA_ENTER) {
				password[i] = '\0';
				break;
				
			} else if (caracter == TECLA_BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}	
			}
            else {
                if (i < LONGITUD){
                    printf("*");
                    password[i] = caracter;
                    i++;
                }
            }
            

		}
        for (j = 0; j < NUMERO_USUARIOS; ++j) {
            if (strcmp(user, users[j]) == 0 && strcmp(password, passwords[j]) == 0) {
                enter = 1;
                break;
            }
        }

        if (enter == 0) {
            printf("\n Error: User or Password Incorrect");
            try++;
            getchar();
        }
		
		
	} while (try < MAX_INTENTOS && enter == 0);
	
	if (enter == 1) {
		printf("\n Welcome...");
	} 
    else {
		printf("\n Exceed Limit");
	}

	return 0;
}

void gotoxy(int x,int y){

    HANDLE Ventana;
    COORD Coordenates;
    Ventana = GetStdHandle(STD_OUTPUT_HANDLE);

    Coordenates.X = x;
    Coordenates.Y = y;

    SetConsoleCursorPosition(Ventana,Coordenates);
}