#include <stdio.h>

int main() {
   printf("Festa das Nações - Leandro Ribeiro de Souza \n\n");

   float totalCaixa = 0, totalTemp, valorTotalFichas2, valorTotalFichas5;
   char continua;
   int qtdFichas2, qtdFichas5, totalFichas2 = 0, totalFichas5 = 0, qtdClientes = 0;

   do {
      printf("Informe o total de fichas de R$2.00: ");
      scanf("%i", &qtdFichas2);
      totalFichas2+= qtdFichas2;

      printf("Informe o total de fichas de R$5.00: ");
      scanf("%i", &qtdFichas5);
      totalFichas5+= qtdFichas5;

      totalTemp = qtdFichas2 * 2 + qtdFichas5 * 5;
      totalCaixa+= totalTemp;

      printf("Valor da venda atual: R$%0.2f.\n", totalTemp);
      printf("Total das vendas: R$%0.2f.\n", totalCaixa);

      printf("\nExistem mais pessoas na fila (S para sim e N para não)?: ");
      scanf(" %c", &continua);
      printf("\n");
      qtdClientes++;

   } while (continua == 'S');

   valorTotalFichas2 = totalFichas2 * 2;
   valorTotalFichas5 = totalFichas5 * 5;

   printf("RELATÓRIO DE VENDAS\n");
   printf("Total de clientes: %i.\n", qtdClientes);
   printf("Quantidade de fichas de R$2.00 vendidas: %i.\n", totalFichas2);
   printf("Valor vendido em fichas de R$2.00: R$%0.2f.\n", valorTotalFichas2);
   printf("Quantidade de fichas de R$5.00 vendidas: %i\n", totalFichas5);
   printf("Valor vendido em fichas de R$5.00: R$%0.2f.\n", valorTotalFichas5);
   printf("Valor total de Vendas: R$%0.2f.\n", totalCaixa);

   return 0;
}
