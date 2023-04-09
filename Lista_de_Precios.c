#include <stdio.h>
#include <stdlib.h>

struct List_of_Prices {
    int id;
    char desc[50];
    int price;
};

int main() {

    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file...");
        return 1;
    }

    struct List_of_Prices List[100];
    int i; 

    
    return 0;
}