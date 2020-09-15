#include <stdio.h>

int main() {
   printf("João das Contas - Leandro Ribeiro de Souza \n\n");

   float valorDoado, totalArrecadado = 0;

   while (totalArrecadado < 20000) {
      printf("Informe o valor doado: R$");
      scanf("%f", &valorDoado);

      totalArrecadado+= valorDoado;

      printf("Valor Arrecadado: R$%0.2f.\n\n", totalArrecadado);
   }

   printf("Valor final arrecadado: R$%0.2f.", totalArrecadado);

   return 0;
}
