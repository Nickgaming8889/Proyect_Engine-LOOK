#include <stdio.h>
#include <math.h>

typedef struct {
    float stdpiston_nissan;
    float limitstd_nissan;
    float toten;
    float totwenty;
    float tothirty;
    float piston_1T;
    float piston_1L;
    float piston_2T;
    float piston_2L;
    float piston_3T;
    float piston_3L;
    float piston_4T;
    float piston_4L;
    float piston_5T;
    float piston_5L;
    float piston_6T;
    float piston_6L;
    float piston_7T;
    float piston_7L;
    float piston_8T;
    float piston_8L;
}RorN;

typedef struct{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[20];
    char phone[20];
    RorN var;
}Clients;

float variables(Clients *engine) {
    engine->var.stdpiston_nissan = 80.465;
    engine->var.limitstd_nissan = 80.515;
    engine->var.toten = 80.565;
    engine->var.totwenty = 80.665;
    engine->var.tothirty = 80.765;
    return 0;
}

Clients engine;

int main(int argc, char*argv[]) {
    int ret, num_piston;
    char buffer[100];

    printf("Choose how much pistons have the engine (4 to 8): ");
    ret = scanf("%d", &num_piston);
    while (getchar() != '\n');
    if (ret != 1) {
        printf("\nInvalid option, enter a number between 4 to 8: ");
        fgets(buffer, sizeof(buffer), stdin);
    }

    switch (num_piston) {
        case 4: {

            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_1T, &engine[0].var.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_2T, &engine->var.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_3T, &engine->var.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_4T, &engine->var.piston_4L);

            float max1 = fmax(engine->var.piston_1T, fmax(engine->var.piston_2T, fmax(engine->var.piston_3T, engine->var.piston_4T)));
            float max2 = fmax(engine->var.piston_1L, fmax(engine->var.piston_2L, fmax(engine->var.piston_3L, engine->var.piston_4L)));
            float mmax = fmax(max1, max2);

            printf("%f", mmax);

            if (mmax > engine->var.stdpiston_nissan && mmax < engine->var.limitstd_nissan) {
                printf("By the moment it don need to be rectify");
            }
            else if (mmax > engine->var.limitstd_nissan && mmax < engine->var.toten) {
                printf("Rectification to 0.10mm.");
            }
            else if (mmax > engine->var.toten && mmax < engine->var.totwenty) {
                printf("Rectification to 0.20mm.");
            }
            else if (mmax > engine->var.totwenty && mmax < engine->var.tothirty) {
                printf("Rectification to 0.30mm.");
            }
            else {
                printf("It's better change pieces and recover monoblock glass...");
            }

            break;
        }
        case 6: {
            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_1T, &engine->var.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_2T, &engine->var.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_3T, &engine->var.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_4T, &engine->var.piston_4L);

            printf("\nPiston 5 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_5T, &engine->var.piston_5L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_6T, &engine->var.piston_6L);

            float max1 = fmax(engine->var.piston_1T, fmax(engine->var.piston_2T, fmax(engine->var.piston_3T, fmax(engine->var.piston_4T, fmax(engine->var.piston_5T, engine->var.piston_6T)))));
            float max2 = fmax(engine->var.piston_1L, fmax(engine->var.piston_2L, fmax(engine->var.piston_3L, fmax(engine->var.piston_4L, fmax(engine->var.piston_5L, engine->var.piston_6L)))));
            float mmax = fmax(max1, max2);

            printf("%f", mmax);

            if (mmax >= engine->var.stdpiston_nissan && mmax <= engine->var.limitstd_nissan) {
                printf("By the moment it don need to be rectify");
            }
            else if (mmax > engine->var.limitstd_nissan && mmax < engine->var.toten) {
                printf("Rectification to 0.10mm.");
            }
            else if (mmax > engine->var.toten && mmax < engine->var.totwenty) {
                printf("Rectification to 0.20mm.");
            }
            else if (mmax > engine->var.totwenty && mmax < engine->var.tothirty) {
                printf("Rectification to 0.30mm.");
            }
            else {
                printf("It's better change pieces and recover monoblock glass...");
            }
            break;
        }
        case 8: {
            printf("\nPiston 1 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_1T, &engine->var.piston_1L);

            printf("\nPiston 2 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_2T, &engine->var.piston_2L);

            printf("\nPiston 3 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_3T, &engine->var.piston_3L);

            printf("\nPiston 4 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_4T, &engine->var.piston_4L);

            printf("\nPiston 5 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_5T, &engine->var.piston_5L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_6T, &engine->var.piston_6L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_7T, &engine->var.piston_7L);

            printf("\nPiston 6 Measurements Transverse and Long: ");
            scanf("%f %f", &engine->var.piston_8T, &engine->var.piston_8L);

            float max1 = fmax(engine->var.piston_1T, fmax(engine->var.piston_2T, fmax(engine->var.piston_3T, fmax(engine->var.piston_4T, fmax(engine->var.piston_5T, fmax(engine->var.piston_6T, fmax(engine->var.piston_7T, engine->var.piston_8T)))))));
            float max2 = fmax(engine->var.piston_1L, fmax(engine->var.piston_2L, fmax(engine->var.piston_3L, fmax(engine->var.piston_4L, fmax(engine->var.piston_5L, fmax(engine->var.piston_6L, fmax(engine->var.piston_7L, engine->var.piston_8L)))))));
            float mmax = fmax(max1, max2);

            printf("%f", mmax);

            if (mmax >= engine->var.stdpiston_nissan && mmax <= engine->var.limitstd_nissan) {
                printf("By the moment it don need to be rectify");
            }
            else if (mmax > engine->var.limitstd_nissan && mmax < engine->var.toten) {
                printf("Rectification to 0.10mm.");
            }
            else if (mmax > engine->var.toten && mmax < engine->var.totwenty) {
                printf("Rectification to 0.20mm.");
            }
            else if (mmax > engine->var.totwenty && mmax < engine->var.tothirty) {
                printf("Rectification to 0.30mm.");
            }
            else {
                printf("It's better change pieces and recover monoblock glass...");
            }
            break;
        }
    }
    return 0;
}
