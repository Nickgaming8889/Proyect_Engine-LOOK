#include <stdio.h>

int main() {
    int total = 100;
    int i;

    for (i = 1; i <= total; i++) {
        printf("Progress [%-20s] %d%%\r", "====================", i);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}