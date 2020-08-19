#include <stdio.h>

int main() {
   printf("Nheco-Cola - Leandro Ribeiro de Souza \n\n");

   int qtdLata, qtdGarrafaP, qtdGarrafaG = 0;
   float litrosTotal;

   printf("Informe o total de Latas compradas: ");
   scanf("%i", &qtdLata);

   printf("Informe o total de Garrafas de 350ml compradas: ");
   scanf("%i", &qtdGarrafaP);

   printf("Informe o total de Garrafas de 2L compradas: ");
   scanf("%i", &qtdGarrafaG);

   litrosTotal = qtdLata * 0.35 + qtdGarrafaP * 0.6 + qtdGarrafaG * 2;

   printf("\nValor total de litros vendidos: %gL.", litrosTotal);

   return 0;
   return 0;
}
