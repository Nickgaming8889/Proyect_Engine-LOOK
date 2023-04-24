#include <stdio.h>

typedef struct{
    int id;
    char name[50];
    float price;
}Article;

void cost(Article data) {

    printf("Cotizacion de rectificacion\n");
    

}

int main(int argc, char *argv[]) {
    
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    Article articles[50];
    int i = 0;

    while (!feof(file)) {
        fscanf(file, "%d %s %f", &articles[i].id, articles[i].name, &articles[i].price);
        i++;
    }

    fclose(file);

    printf("Read %d articles:\n", i);

    for (int j = 0; j < i; j++) {
        printf("Article %d:\n", j+1);
        printf("ID: %d\n", articles[j].id);
        printf("Name: %s\n", articles[j].name);
        printf("Price: %.2f\n", articles[j].price);
    }

    int article_id;
    printf("Enter article ID to search: ");
    scanf("%d", &article_id);

    for (int j = 0; j < i; j++) {
        if (articles[j].id == article_id) {
            printf("Article %d:\n", j+1);
            printf("ID: %d\n", articles[j].id);
            printf("Name: %s\n", articles[j].name);
            printf("Price: %.2f\n", articles[j].price);
            break;
        }
        if (j == i-1) {
            printf("Article not found\n");
        }
    }

    return 0;
}