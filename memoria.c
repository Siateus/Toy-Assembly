#include <string.h>
#include <stdio.h>
#include "memoria.h"
extern int MEMORIA[1000];
extern int registradores[32];

void Load(char memoria[], char operador[]);

void store(char memoria[], char operador[]);

void ram(char instrucoes[], char memoria[], char operador[]){

    if ((strcmp(instrucoes, "LOAD") == 0)){
        Load(memoria, operador);
    }
    if((strcmp(instrucoes, "STORE") == 0)){
        store(memoria,operador);
    }
}

void store(char memoria[], char operador[]) {
    int rx, ry;
    int valor, endereco;
    sscanf(memoria+1,"%d",&valor);
    sscanf(operador+1,"%d",&endereco);
    rx = registradores[valor];
    ry = registradores[endereco];
    MEMORIA[ry] = rx;

}

void Load(char memoria[], char operador[]) {
    int ry, rx, RY, RX;
    sscanf(memoria+1,"%d",&rx);
    sscanf(operador+1,"%d",&RY);
    ry = registradores[RY];
    registradores[rx] = MEMORIA[ry];
   // registradores[rx] = RX;
}
