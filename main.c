#include <stdio.h>
#include "leitura.h"
int registradores[32] = {0}; // 32 elementos, de R0 até R31
int MEMORIA[1000] = {0}; // Um array  para a memoria com 1000 elementos.


int main() {
    ler_dados();
    return 0;
}
