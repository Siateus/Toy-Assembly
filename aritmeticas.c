#include <stdio.h>
#include <string.h> // Para strcmp
#include "aritmeticas.h"
extern int registradores[32];

void calculadora(char instrucoes[], char destino[], char operador[], char operador_2[]){
    int op_1, op_2, des;
    int rx, ry, rz;

    if (strcmp(instrucoes, "ADD") == 0){
        sscanf(destino+1, "%d", &des);
        sscanf(operador+1, "%d", &op_1);
        sscanf(operador_2+1, "%d", &op_2);
        ry = registradores[op_1];
        rz = registradores[op_2];
        rx = ry + rz;
        registradores[des] = rx;
    }
    if (strcmp(instrucoes, "SUB") == 0){
        sscanf(destino+1, "%d", &des);
        sscanf(operador+1, "%d", &op_1);
        sscanf(operador_2+1, "%d", &op_2);
        ry = registradores[op_1];
        rz = registradores[op_2];
        rx = ry - rz;
        registradores[des] = rx;
    }
    if (strcmp(instrucoes, "MUL") == 0){
        sscanf(destino+1, "%d", &des);
        sscanf(operador+1, "%d", &op_1);
        sscanf(operador_2+1, "%d", &op_2);
        ry = registradores[op_1];
        rz = registradores[op_2];
        rx = ry * rz;
        registradores[des] = rx;
    }
    if (strcmp(instrucoes, "DIV") == 0){
        sscanf(destino+1, "%d", &des);
        sscanf(operador+1, "%d", &op_1);
        sscanf(operador_2+1, "%d", &op_2);
        ry = registradores[op_1];
        rz = registradores[op_2];
        rx = ry / rz;
        registradores[des] = rx;
    }
    if (strcmp(instrucoes, "MOD") == 0){
        sscanf(destino+1, "%d", &des);
        sscanf(operador+1, "%d", &op_1);
        sscanf(operador_2+1, "%d", &op_2);
        ry = registradores[op_1];
        rz = registradores[op_2];
        rx = ry % rz;
        registradores[des] = rx;
    }
}
