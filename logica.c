#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "logica.h"

extern int registradores[32];
extern int MEMORIA[1000];

int logica(char instrucoes[], char operador[], char operador_2[]){
    int rx, ry;
    int RX, RY;
    int comparacao;

    if(strcmp(instrucoes,"BEQ")==0){
        sscanf(operador,"R%d",&rx);
        sscanf(operador_2,"R%d",&ry);
        RY = registradores[ry];
        RX = registradores[rx];
        comparacao = (RX == RY) ? 0 : 1;
       // printf("%d\n",comparacao);
        return comparacao;

    }
    if (strcmp(instrucoes,"BLT")==0){
        sscanf(operador+1,"%d",&rx);
        sscanf(operador_2+1,"%d",&ry);
        RX = registradores[rx];
        RY = registradores[ry];
        if(RX < RY) {
            return 0;
        } else{
            return 1;
        }
    }
}

int jmp(int endereco){
    //printf("\ndentro do jump %d\n",endereco);
    return endereco;
}