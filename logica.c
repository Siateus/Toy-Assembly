#include <string.h>
#include <stdio.h>
#include "logica.h"

extern int registradores[32];

int logica(char instrucoes[], char operador[], char operador_2[]){
    int rx, ry;
    int RX, RY;
    int comparacao;
    if(strcmp(instrucoes,"BEQ")==0){
        sscanf(operador+1,"%d",&rx);
        sscanf(operador_2+1,"%d",&ry);
        RX = registradores[rx];
        RY = registradores[ry];
        comparacao = (RX == RY) ? 1 : 0;
        return comparacao;
    }
    if (strcmp(instrucoes,"BLT")==0){
        sscanf(operador+1,"%d",&rx);
        sscanf(operador_2+1,"%d",&ry);
        RX = registradores[rx];
        RY = registradores[ry];
        comparacao = (RX < RY) ? 1 : 0;
        return comparacao;
    }
}
int jmp(int endereco){
    return endereco;
}