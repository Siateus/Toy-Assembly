#include <stdio.h>
#include "control.h"
#include "aritmeticas.h"
#include "memoria.h"
#include "logica.h"
#include "saida.h"
#include <string.h>
#define TAM 12

extern int registradores[32]; // Um array externo para a registradores com 32 elementos.
extern int MEMORIA[1000];

// Função para mover valores entre registradores ou constantes.
int mov(char destino[], char operador[]){
    int mov_int;
    int x,y ;
    if (operador[0]!='R'){
        // Se o operador não começa com 'R', é uma constante.
        sscanf(destino+1, "%d", &mov_int);
        sscanf(operador, "%d", &x);
        registradores[mov_int] = x;
    } else {
        // Se o operador começa com 'R', é um registrador.
        sscanf(destino+1, "%d", &mov_int);
        sscanf(operador+1, "%d", &y);
        registradores[mov_int] = registradores[y];
    }
    return 0; // Valor de retorno, se necessário.
}

// Função de controle principal para executar as instruções.
void controle(char matriz[100][17], int n) {
    int indice, resposta = 0, pula, count = 0;
    char instrucoes[8];
    char destino[TAM], operador[TAM], operador_2[TAM];

    for (int i = 0; i < n; ) {
        // Cada iteração do loop processa uma instrução da matriz.

        if (strncmp(matriz[i], "MOV", 3) == 0 ){
            //Se a instrução é "MOV", realiza uma movimentação de valor.
            sscanf(matriz[i], "%s%s%s", instrucoes, destino, operador);
            mov(destino, operador);
        }

        else if(strncmp(matriz[i], "ADD", 3) == 0 || strncmp(matriz[i], "SUB", 3) == 0 ||
           strncmp(matriz[i], "DIV", 3) == 0 || strncmp(matriz[i], "MUL", 3) == 0 ||
           strncmp(matriz[i], "MOD", 3) == 0) {
            // Se a instrução é uma operação aritmética, chama a função calculadora.
            sscanf(matriz[i], "%s%s%s%s", instrucoes, destino, operador, operador_2);
            calculadora(instrucoes, destino, operador, operador_2);
        }

        else if(strncmp(matriz[i], "LOAD", 4) == 0 || strncmp(matriz[i], "STORE", 5) == 0) {
            // Se a instrução envolve operações de "LOAD"/"STORE" na memória, chama a função ram.
            sscanf(matriz[i], "%s%s%s", instrucoes, destino, operador);
            ram(instrucoes, destino, operador);
        }

        else if(strncmp(matriz[i], "BEQ", 3) == 0 || strncmp(matriz[i], "BLT", 3) == 0 || strncmp(matriz[i], "JMP", 3) == 0) {
            if(strncmp(matriz[i], "JMP", 3) == 0) {
                // Se a instrução é "JMP", realiza um salto.
                sscanf(matriz[i], "%s%d", instrucoes, &indice);
                pula = jmp(indice);
                i = pula-1;
            } else {
                // Se a instrução é "BEQ" ou "BLT", realiza um salto condicional com base na resposta da função logica.
                sscanf(matriz[i], "%s%s%s%d", instrucoes, operador, operador_2, &indice);
                resposta = logica(instrucoes, operador, operador_2);
                i = (resposta == 0) ? indice-1 : i; // Comentário: Pula para o índice se a resposta for falsa (0).
            }
        }

        else if(strncmp(matriz[i], "PRINT", 5) == 0){
            // Se a instrução é "PRINT", imprime o valor do registrador.
            sscanf(matriz[i], "%s%s", instrucoes, operador);
            imprimir(operador);
        }

        else if(strncmp(matriz[i], "EXIT", 4) == 0 || count == 100000){
            // Se a instrução é "EXIT" ou se atingimos um limite de execuções, encerra o loop.
            break;
        }
        count++;
        i++;
    }
}
