#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void main() {

    system("cls");
    gotoxy(40,3);
    printf("Welcome to Engine LOOK");
    gotoxy(43,4);
    printf("Loading Program...");
    gotoxy(31,6);
    printf("Created by: Nicholas Caceres Version 1.23");

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
