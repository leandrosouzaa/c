#include <stdio.h>

int main() {
   printf("Festa das Nações - Leandro Ribeiro de Souza \n\n");

   float totalCaixa = 0, totalTemp;
   char continua;
   int qtdFichas2, qtdFichas5;

   do {
      printf("Informe o total de fichas de R$2.00: ");
      scanf("%i", &qtdFichas2);

      printf("Informe o total de fichas de R$5.00: ");
      scanf("%i", &qtdFichas5);

      totalTemp = qtdFichas2 * 2 + qtdFichas5 * 5;
      totalCaixa+= totalTemp;

      printf("Total da venda: R$%0.2f.\n", totalTemp);
      printf("Total das vendas: R$%0.2f.\n", totalCaixa);

      printf("Existem mais pessoas na fila (S para sim e N para não)?: ");
      scanf(" %c", &continua);
      printf("\n");

   } while (continua == 'S');

   printf("RELATÓRIO DE VENDAS\n");
   printf("Valor total de Vendas: R$%0.2f.", totalCaixa);

   return 0;
}
