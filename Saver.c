/*#include <stdio.h>
#include <math.h>

struct RorN{
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
};

typedef struct{
    char name_clt[80];
    char mk[50];
    char nsm[20];
    char plt[10];
    char year[20];
    char phone[20];
}Clients;

float variables() {
    struct RorN engine;

    engine.stdpiston_nissan = 80.465;
    engine.limitstd_nissan = 80.515;
    engine.toten = 80.565;
    engine.totwenty = 80.665;
    engine.tothirty = 80.765;

    printf("%.3f", engine.limitstd_nissan);

    return 0;
}

int main(int argc, char*argv[]) {
    //int ret, num_piston;
    //char buffer[100];

    struct RorN engine;

    variables();

    return 0;
}*/

#include <stdio.h>
#include <stdbool.h>

struct ValidacionRectificacion {
   float diametro_piston_referencia;
   float diametro_piston_medida;
   float altura_piston_referencia;
   float altura_piston_medida;
   float holgura_referencia;
   float holgura_medida;
};

float llenarReferencia(struct ValidacionRectificacion* validacion) {
   validacion->diametro_piston_referencia = 85.0;
   validacion->altura_piston_referencia = 50.0;
   validacion->holgura_referencia = 0.2;

   return 0;
}

float llenarMedida(struct ValidacionRectificacion* validacion) {
   validacion->diametro_piston_medida = 85.2;
   validacion->altura_piston_medida = 50.1;
   validacion->holgura_medida = 0.15;

   return 0;
}

bool validarRectificacion(struct ValidacionRectificacion* validacion) {
   bool resultado = true;
   if (validacion->diametro_piston_medida > validacion->diametro_piston_referencia) {
      resultado = false;
   }
   if (validacion->altura_piston_medida > validacion->altura_piston_referencia) {
      resultado = false;
   }
   if (validacion->holgura_medida > validacion->holgura_referencia) {
      resultado = false;
   }
   return resultado;
}

int main(int arg, char *argv[]) {
   struct ValidacionRectificacion validacion;
   llenarReferencia(&validacion);
   llenarMedida(&validacion);
   bool resultado = validarRectificacion(&validacion);
   if (resultado) {
      printf("La rectificacion fue exitosa\n");
   } else {
      printf("La rectificacion no fue exitosa\n");
   }
   return 0;
}
