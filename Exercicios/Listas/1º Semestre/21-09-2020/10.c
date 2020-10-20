#include <stdio.h>

int main() {
   printf("Contas de uma Rua - Leandro Ribeiro de Souza \n\n");

   int i =0, indexMenorConta;
   float contas[25], total = 0, icms, valorMaiorConta, icmsIndividual;

   for (i=0; i < 25; i++) {
      printf("Conta da Casa %i: R$", i + 1);
      scanf("%f", &contas[i]);
   }

   total = contas[0];
   valorMaiorConta = contas[0];
   indexMenorConta = 0;
   for (i=1; i < 25; i++) {
      total+= contas[i];

      if (contas[i] > valorMaiorConta) {
         valorMaiorConta = contas[i];
      }

      if (contas[indexMenorConta] > contas[i]) {
         indexMenorConta = i;
      }
   }
   icms = total * 0.25;

   printf("\nRELATÓRIO FINAL\n");
   printf("Casa que menos gastou Energia: %i.\n", indexMenorConta + 1);
   printf("Valor da conta mais cara: R$%0.2f.\n", valorMaiorConta);
   printf("Total das contas: R$%0.2f.\n", total);
   printf("Valor total pago ICMS: %0.2f.\n", icms);
   printf("\nICMS POR CASA\n");
   for (i=0; i < 25; i++) {
      icmsIndividual = contas[i] * 0.25;
      printf("ICMS pago pela casaa %d: R$%0.2f.\n", i + 1, icmsIndividual);
   }

   return 0;
}
