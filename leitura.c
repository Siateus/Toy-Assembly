
#include <stdio.h>
#include "leitura.h"
#include "control.h"

void ler_matriz(int n, char matriz[100][17]) {
    for(int i = 0; i < n; i++){
        scanf("%[^\n]%*c", matriz[i]);
    }
    controle(matriz,n);
}

void ler_dados(){
    int n;
    scanf("%d ",&n);
    char matriz[100][17];
    ler_matriz(n, matriz);

}
