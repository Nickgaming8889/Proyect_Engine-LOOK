#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int gotoxy(int x, int y);
int Timer();

int main() {

    system("cls");
    gotoxy(40,3);
    printf("Welcome to Engine LOOK");
    gotoxy(43,4);
    printf("Loading Program...");
    gotoxy(31,6);
    printf("Created by: Nicholas Caceres Version 1.23\n\n");

    Timer();

    return 0;
}

int gotoxy(int x,int y){

    HANDLE Ventana;
    COORD Coordenates;
    Ventana = GetStdHandle(STD_OUTPUT_HANDLE);

    Coordenates.X = x;
    Coordenates.Y = y;

    SetConsoleCursorPosition(Ventana,Coordenates);

    return 0;
}

int Timer() {
    int total = 100;
    int i;

    for (i = 1; i <= total; i++) {
        gotoxy(32,8);
        printf("Progress [%-20s] %d%%\r", "====================", i);
        fflush(stdout);
        Sleep(200);
    }

    return 0;
}