#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "logica.h"

extern int registradores[32]; // Um array externo para a registradores com 32 elementos.

// Função que lida com instruções de lógica BEQ e BLT.
int logica(char instrucoes[], char operador[], char operador_2[]){
    int rx, ry;     // Variáveis para armazenar números de registradores.
    int RX, RY;     // Variáveis para armazenar valores de registradores.
    int comparacao; // Variável para armazenar o resultado da comparação.

    if (strcmp(instrucoes, "BEQ") == 0) {
        sscanf(operador, "R%d", &rx);
        sscanf(operador_2, "R%d", &ry);
        RY = registradores[ry];
        RX = registradores[rx];
        comparacao = (RX == RY) ? 0 : 1; // Compara RX e RY, retorna 0 se igual, 1 se diferente.
        return comparacao; // Retorna o resultado da comparação.
    }

    if (strcmp(instrucoes, "BLT") == 0) {
        sscanf(operador + 1, "%d", &rx);
        sscanf(operador_2 + 1, "%d", &ry);
        RX = registradores[rx];
        RY = registradores[ry];
        comparacao = (RX < RY) ? 0 : 1; // Compara RX e RY, retorna 0 se RX < RY, 1 caso contrário.
        return comparacao; // Retorna o resultado da comparação.
    }
}

// Função que implementa um salto (JMP) para um determinado endereço.
int jmp(int endereco) {
    return endereco; // Retorna o endereço para onde deve ser feito o salto.
}
