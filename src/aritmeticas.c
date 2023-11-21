#include <stdio.h>
#include <string.h> // Para strcmp
#include "../include/aritmeticas.h"

extern int registradores[32];

// Função que lida com instruções aritméticas (ADD, SUB, MUL, DIV, MOD).
void calculadora(char instrucoes[], char destino[], char operador[], char operador_2[]){
    int op_1, op_2, des; // Variáveis para operandos e destino.
    int rx, ry, rz;     // Variáveis para armazenar valores de registradores.

    // Extrai os números dos registradores e destino a partir das strings.
    sscanf(destino + 1, "%d", &des);
    sscanf(operador + 1, "%d", &op_1);
    sscanf(operador_2 + 1, "%d", &op_2);

    // Lê os valores dos registradores de acordo com os operandos.
    ry = registradores[op_1];
    rz = registradores[op_2];

    // Realiza a operação apropriada com base na instrução.
    if (strncmp(instrucoes, "ADD", 3) == 0){
        rx = ry + rz; // Soma os valores.
    }
    else if (strncmp(instrucoes, "SUB", 3) == 0){
        rx = ry - rz; // Subtrai os valores.
    }
    else if (strncmp(instrucoes, "MUL", 3) == 0){
        rx = ry * rz; // Multiplica os valores.
    }
    else if (strncmp(instrucoes, "DIV", 3) == 0){
        rx = ry / rz; // Divide os valores.
    }
    else if (strncmp(instrucoes, "MOD", 3) == 0){
        rx = ry % rz; // Calcula o resto da divisão.
    }

    // Armazena o resultado da operação no registrador de destino.
    registradores[des] = rx;
}
