#include <stdio.h>

int main() {
   printf("João das Contas - Leandro Ribeiro de Souza \n\n");

   float valorDoado, totalArrecadado = 0;
   int totalDoadores = 0;

   while (totalArrecadado < 20000) {
      printf("Informe o valor doado: R$");
      scanf("%f", &valorDoado);

      totalArrecadado+= valorDoado;
      totalDoadores++;

      printf("Valor Arrecadado: R$%0.2f.\n\n", totalArrecadado);
   }

   printf("RELATÓRIO DE DOADORES\n");
   printf("Total de doadores: %i.\n", totalDoadores);
   printf("Valor final arrecadado: R$%0.2f.", totalArrecadado);

   return 0;
}
