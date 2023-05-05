#include <stdio.h>

typedef struct {
    float stdpiston;
    float limitstd;
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

float variables(Clients *user) {
    user->var.stdpiston = 80.465;
    user->var.limitstd = 80.515;
    return 0;
}

int main() {
    
}