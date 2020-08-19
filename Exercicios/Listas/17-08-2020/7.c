#include <stdio.h>

int main() {
   printf("Fábrica de Camisetas - Leandro Ribeiro de Souza \n\n");

   int qtdP, qtdM, qtdG = 0;
   float valorTotal;

   printf("Informe o total de camisetas PEQUENAS compradas: ");
   scanf("%i", &qtdP);

   printf("Informe o total de camisetas MÉDIAS compradas: ");
   scanf("%i", &qtdM);

   printf("Informe o total de camisetas GRANDES compradas: ");
   scanf("%i", &qtdG);

   valorTotal = qtdP * 15 + qtdM * 22 + qtdP * 25;

   printf("\nValor total arrecadado nessa venda: R$%g.", valorTotal);

   return 0;
}
