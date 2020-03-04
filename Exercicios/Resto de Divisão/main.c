#include <stdio.h>
#include <stdlib.h>

int main() {

    int x,y, resto, resultado;

    printf("Resto de Divisão - Leandro Ribeiro de Souza\n\n");

    printf("Informe um número: ");
    scanf("%i", &x);

    printf("Informe outro número: ");
    scanf("%i", &y);

    resultado = x/y;
    resto = x%y;

    printf("O resultado da divisão de X por Y é %i\n", resultado);
    printf("O resto da divisão é %i", resto);

    return 0;

}