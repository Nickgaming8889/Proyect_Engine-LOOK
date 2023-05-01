#include <stdio.h>

typedef struct{
    int id;
    char name[50];
    int num_part;
    float price;
}Article;

int main() {
    int ret;
    char buffer[100];
    
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

    int o;

    printf("Read %d articles:\n", i);

    for (int j = 0; j < i; j++) {
        printf("Article %d:\n", j+1);
        printf("ID: %d Name: %s Parts: %d Price: %.2f\n", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);

        int article_id;
        printf("Enter article ID to search: ");
        ret = scanf("%d", &article_id);
        while (getchar() != '\n');
        if (ret != 1) {
            printf("Invalid option, please put a number... ");
            fgets(buffer, sizeof(buffer), stdin);
            //continue;
        }

        for (int j = 0; j < i; j++) {
            if (articles[j].id == article_id) {
                printf("Article %d:\n", j+1);
                printf("ID: %d Name: %s Parts: %d Price: %.2f\n", articles[j].id, articles[j].name, articles[j].num_part, articles[j].price);

                int new_quantity;
                printf("Enter new quantity for article %d (%s): ", article_id, articles[j].name);
          
                ret = scanf("%d", &new_quantity);
                while (getchar() != '\n');
                if (ret != 1) {
                    printf("Invalid option, please put a number... ");
                    fgets(buffer, sizeof(buffer), stdin);
                    //continue;
                }

                articles[j].num_part += new_quantity;
                float cost = new_quantity * articles[j].price;

                printf("New quatity for article %d (%s): %d Cost: %2f", article_id, articles[j].name, articles[j].num_part, cost);

                printf("\n\nDo you want to continue buying articles? y(1)/n(2) ");
                ret = scanf("%d", &o);
                while (getchar() != '\n');
                if (ret != 1) {
                printf("Invalid option, please put a number... ");
                fgets(buffer, sizeof(buffer), stdin);
                //continue;
                }
            }
            if (j == i-1) {
                printf("Article not found\n");
            }
        }
    }

    return 0;
}