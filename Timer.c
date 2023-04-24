#include <stdio.h>
#include <windows.h>

int main() {
    int total = 100;
    int i;

    for (i = 1; i <= total; i++) {
        printf("Progress [%-20s] %d%%\r", "====================", i);
        fflush(stdout);
        Sleep(200);
    }

    return 0;
}