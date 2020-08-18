#include <stdio.h>
#include <stdlib.h>

int main() {

    int x,y,soma,mult,sub,div = 0;

    printf("Calculadora 1.0 - Leandro Ribeiro de Souza \n");
    printf("Por favor, informe dois números:\n");
    scanf("%i%i",&x,&y);

    soma = x + y;
    sub = x - y;
    mult = x * y;
    div = x / y;

    printf("O resultado da soma entre esses dois números é %i.\n" , soma);
    printf("O resultado da subtração entre esses dois números é %i.\n", sub);
    printf("O resultado da multiplicação entre esses dois números é %i.\n", mult);
    printf("O resultado da divisão entre esses dois números é %i.\n", div);

    return 0;
}