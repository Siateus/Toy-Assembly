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
    int rx;
    int memo, ope;
    sscanf(memoria+1,"%d",&memo);
    sscanf(operador+1,"%d",&ope);
    rx = registradores[memo];
    MEMORIA[ope] = rx;


}

void Load(char memoria[], char operador[]) {
    int ry, rx, ope;
    int x, y;
    sscanf(memoria+1,"%d",&rx);
    sscanf(operador+1,"%d",&ope);
    ry = registradores[ope];
    registradores[rx] = MEMORIA[ry];

}
