#include <string.h>
#include <stdio.h>
#include "../include/memoria.h"
extern int MEMORIA[1000]; // Um array externo para a memória com 1000 elementos.
extern int registradores[32]; // Um array externo para a registradores com 32 elementos.

void Load(char memoria[], char operador[]);

void store(char memoria[], char operador[]);

void ram(char instrucoes[], char memoria[], char operador[]){

    if ((strcmp(instrucoes, "LOAD") == 0)){
        int ry, rx, RY;
        sscanf(memoria+1,"%d",&rx);
        sscanf(operador+1,"%d",&RY);
        ry = registradores[RY]; // Lê o valor do registrador correspondente ao índice "valor" e armazena em "ry".
        registradores[rx] = MEMORIA[ry];// Lê o valor da memória no endereço "ry" e armazena no registrador com o índice "rx".
    }
    else if((strcmp(instrucoes, "STORE") == 0)){
        int rx, ry;
        int valor, endereco;
        sscanf(memoria+1,"%d",&valor);
        sscanf(operador+1,"%d",&endereco);
        rx = registradores[valor]; // Lê o valor do registrador correspondente ao índice "valor" e armazena em "rx".
        ry = registradores[endereco]; // Lê o valor do registrador correspondente ao índice "endereco" e armazena em "ry".
        MEMORIA[ry] = rx; // Armazena o valor de "rx" na memória no endereço especificado por "ry".
    }
}

