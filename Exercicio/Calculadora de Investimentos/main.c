#include <stdlib.h>
#include <stdio.h>

int main() {
    float m, i, p, n, x, M, lucro, porcentagem;
    /*
        m = lucro bruto;
        p = investimento inicial
        i = taxa de juros;
        n = quantidade de meses;
        x = utilizado para o for;
        M = lucro bruto após o desconto de IOF;
        lucro = lucro liquido;
        porcentagem = porcentagem de lucro em relação ao investimento;
        
    */

    printf("\n Calculadora de Investimentos - Leandro Ribeiro de Souza\n\n");

    printf("Informe o valor do seu investimento: R$");
    scanf("%f", &p);

    printf("Informe a taxa de juros(): ");
    scanf("%f", &i);

    printf("Informe o período de duração de seu Investimento(Meses): ");
    scanf("%f", &n);
    
    m = p;

    for (x=0; x<n; x++) {
        m = m *(1+(i/100));
    }

    M = m - (m*0.08);

    lucro = M - p;

    porcentagem = (lucro*100)/ p;


    system("clear");
    printf("O lucro bruto obtido foi de R$%f.\n",m);
    printf("Devido aos descontos do IOF(R$%f) o lucro bruto foi reduzido para R$%f.\n",m*0.08, M);
    printf("O lucro liquido foi de R$%f\n", lucro);
    printf("Foi obtido um lucro de %f%% em relação ao investimento inicial.\n");
    



}