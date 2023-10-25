#include <stdio.h>
#include "control.h"
#include "aritmeticas.h"
#include "memoria.h"
#include "logica.h"
#include "saida.h"
#include <string.h>
#define TAM 12

extern int registradores[32];
extern int MEMORIA[1000];

int mov(char destino[], char operador[]){
    int mov_int;
    int x,y ;
    if (operador[0]!='R'){
        sscanf(destino+1, "%d", &mov_int);
        sscanf(operador, "%d", &x);
        registradores[mov_int] = x;

    }else{
        sscanf(destino+1, "%d", &mov_int);
        sscanf(operador+1, "%d", &y);
        registradores[mov_int] = registradores[y];
    }
     return 0 ;
}

void controle(char matriz[100][17],int n) {
    int indice, resposta=0, pula, count = 0;
    char instrucoes[8];
    char endereco[TAM];
    char destino[TAM], operador[TAM],operador_2[TAM];
    for (int i = 0; i < n; i++) {

        if (strncmp(matriz[i], "MOV", 3) == 0 ){
            sscanf(matriz[i], "%s %s %s", instrucoes, destino, operador);
            mov(destino, operador);
        }

        if(strncmp(matriz[i], "ADD", 3) == 0||strncmp(matriz[i], "SUB", 3) == 0||strncmp(matriz[i], "DIV", 3) == 0||strncmp(matriz[i], "MUL", 3) == 0||
            strncmp(matriz[i], "MOD", 3)==0){
            sscanf(matriz[i],"%s %s %s %s", instrucoes,destino,operador,operador_2 );
            calculadora(instrucoes,destino,operador,operador_2);
        }

        if(strncmp(matriz[i], "LOAD", 4) == 0 ||(strncmp(matriz[i], "STORE", 5) == 0 )){
            sscanf(matriz[i],"%s %s %s ", instrucoes,destino,operador );
            ram(instrucoes,destino,operador);
        }

        if(strncmp(matriz[i], "BEQ", 3) == 0 ||(strncmp(matriz[i], "BLT", 3) == 0 || strncmp(matriz[i], "JMP", 3) == 0)){
            if(strncmp(matriz[i], "JMP", 3) == 0){
                sscanf(matriz[i], "%s %d", instrucoes, &indice);
                pula = jmp(indice);
                i = pula;
            } else{
                sscanf(matriz[i], "%s %s %s %d", instrucoes, operador,operador_2, &indice);
                resposta = logica(instrucoes,operador,operador_2);
                i = (resposta == 0) ? indice : i;
               // printf("%d",i);
            }
        }

        if(strncmp(matriz[i], "PRINT", 5) == 0){
            sscanf(matriz[i], "%s %s", instrucoes, operador);
            imprimir(operador);
        }

        if(strncmp(matriz[i], "EXIT", 4) == 0 || count == 10001 ){
            break;
        }
        count++;
    }
}
