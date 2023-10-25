#include <stdio.h>
#include <string.h> // Para strcmp
#include "aritmeticas.h"

extern int registradores[32];

void calculadora(char instrucoes[], char destino[], char operador[], char operador_2[]){
    int op_1, op_2, des;
    int rx, ry, rz;

    sscanf(destino+1, "%d", &des);
    sscanf(operador+1, "%d", &op_1);
    sscanf(operador_2+1, "%d", &op_2);
    ry = registradores[op_1];
    rz = registradores[op_2];

    if (strncmp(instrucoes, "ADD", 3) == 0){
        rx = ry + rz;
    }
    else if (strncmp(instrucoes, "SUB", 3) == 0){
        rx = ry - rz;
    }
    else if (strncmp(instrucoes, "MUL", 3) == 0){
        rx = ry * rz;
    }
    else if (strncmp(instrucoes, "DIV", 3) == 0){
        rx = ry / rz;
    }
    else if (strncmp(instrucoes, "MOD", 3) == 0){
        rx = ry % rz;
    }

    registradores[des] = rx;
}
