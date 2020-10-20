#include <stdio.h>

int main() {
   printf("Três amigos - Leandro Ribeiro de Souza \n\n");

   int valorSemCentavos = 0;
   float valorDaCorrida, valorComCentavos = 0;

   printf("Informe o valor total da corrida: R$");
   scanf("%f", &valorDaCorrida);

   valorSemCentavos = valorDaCorrida / 3;
   valorComCentavos = ((valorDaCorrida / 3) - valorSemCentavos) * 2 + valorDaCorrida / 3;

   printf("\nValor a ser pago pelo dois primeiros: R$%i\n", valorSemCentavos);
   printf("Valor a ser pago pelo ultimo: R$%0.2f", valorComCentavos);

   return 0;
}
