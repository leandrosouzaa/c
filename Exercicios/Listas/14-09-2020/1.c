#include <stdio.h>

int main() {
   printf("Caixa de Mercado - Leandro Ribeiro de Souza \n\n");

   float valorProduto, total;

   do {
      printf("Digite 0 para Sair.\n");
      printf("Informe o valor do Produto: R$");
      scanf("%f", &valorProduto);

      total = valorProduto + total;
      printf("Atual valor da compra: %0.2f\n\n", total);

   } while (valorProduto > 0);

   printf("EXTRATO DA COMPRA\n");
   printf("Valor final da Compra: R$%0.2f.", total);

   return 0;
}
