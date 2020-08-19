#include <stdio.h>

int main() {
   printf("Padaria Hotpão - Leandro Ribeiro de Souza \n\n");

   int qtdBroa, qtdPao=0;
   float valorTotal, valorPoupado, valorFinal, porcentagem=0;

   printf("Informe a quantidade de Broas vendidas: ");
   scanf("%i", &qtdBroa);

   printf("Informe a quantidade de pães vendidos: ");
   scanf("%i", &qtdPao);

   printf("Informe a porcentagem das vendas que deseja poupar: ");
   scanf("%f", &porcentagem);

   valorTotal = qtdBroa*4.50 + qtdPao*0.6;
   valorPoupado = valorTotal * (porcentagem/100);
   valorFinal = valorTotal - valorPoupado;

   printf("\nQuantidade de Broas Vendidas: %i.\n", qtdBroa);
   printf("Quantidade de Pães Vendidos: %i.\n", qtdBroa);
   printf("Total arrecadado com as vendas: R$%g.\n", valorTotal);
   printf("Valor poupado (%g%%): R$%g.\n", porcentagem, valorPoupado);
   printf("Valor restado em Caixa: R$%g.", valorFinal);

   return 0;
}

