#include <stdio.h>
#include <stdlib.h>

int main() {

    char ch;
    FILE *file;

    file = fopen("tttt.txt", "r");
    if (file == NULL) {
        printf("Error al leer...");
        exit(1);
    }

    while (ch != EOF) {
        ch = fgetc(file);
        printf("%c", ch);
    }

    fclose(file);

    system("pause");
    return 0;
}
