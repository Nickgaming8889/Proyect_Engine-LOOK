#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[50];
    int num_part;
    float price;
}Article;

int main() {
    
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    Article articles[50];
    int i = 0;

    while (!feof(file)) {
        fscanf(file, "%d %s %d %f", &articles[i].id, articles[i].name, &articles[i].num_part, &articles[i].price);
        i++;
    }

    fclose(file);

    printf("Read %d articles:\n", i);

    for (int j = 0; j < i; j++) {
        printf("Article %d:\n", j+1);
        printf("ID: %d  ", articles[j].id);
        printf("Name: %s  ", articles[j].name);
        printf("Parts: %d  ", articles[j].num_part);
        printf("Price: %.2f\n", articles[j].price);
    }

    int article_id;
    printf("For which one you want to buy some parts: ");    
    scanf("%d", &article_id);

    for (int j = 0; j < i; j++) {
        if (articles[j].id == article_id) {
            printf("Article %d:\n", j+1);
            printf("ID: %d  ", articles[j].id);
            printf("Name: %s  ", articles[j].name);
            printf("Parts: %d  ", articles[j].num_part);
            printf("Price: %.2f\n", articles[j].price);
            
            int new_quantity;
            printf("Enter new quantity for article %d (%s): ", article_id, articles[j].name);
            scanf("%d", &new_quantity);

            articles[j].num_part += new_quantity;
            float cost = articles[j].price * new_quantity;

            printf("New quantity for article %d (%s): %d Cost: %2f\n", article_id, articles[j].name, articles[j].num_part, cost);

            break;
        }
        if (j == i-1) {
            printf("Article not found\n");
        }
    }

    return 0;
}