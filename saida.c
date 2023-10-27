#include <stdio.h>
#include "saida.h"

extern int registradores[32]; // Um array externo para a registradores com 32 elementos.

void imprimir( char operador[]){
    int rx;
    int RX;
    sscanf(operador+1, "%d", &rx);
    RX = registradores[rx];
    printf("%d\n",RX);

}
