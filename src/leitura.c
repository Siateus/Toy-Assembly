#include <stdio.h>
#include "../include/leitura.h"
#include "../include/control.h"

void ler_matriz(int n, char matriz[100][17]) {
    for(int i = 0; i < n; i++){
        fgets(matriz[i],17,stdin);
    }
    controle(matriz,n);
}

void ler_dados(){
    int n;
    scanf("%d\n",&n);
    char matriz[100][17];
    ler_matriz(n, matriz);
}
