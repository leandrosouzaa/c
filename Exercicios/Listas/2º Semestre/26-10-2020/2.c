#include <stdio.h>

int main() {   
   printf("Controle de Estoque - Leandro Ribeiro de Souza \n");

   int codigos[30], estoques[30], i, tl = 0, indexMaisCaro = 0, indexMaiorEstoque = 0;
   float precos[30];
   char continua;

   do {
      printf("\nCódigo do Produto: ");
      scanf("%d", &codigos[i]);
      do {
         printf("Preço do Produto: R$");
         scanf("%f", &precos[i]);
         if (precos[i] <= 0) {
            printf("Preço inválido, tente novamente.\n");
         }

      } while(precos[i] <= 0);
      do {
         printf("Quantidade em Estoque: ");
         scanf("%d", &estoques[i]);
         if (estoques[i] < 0) {
            printf("Estoque inválido, tente novamente.\n");
         }
      } while(estoques[i] < 0);

      i++;
      tl++;
      printf("\nCadastrar mais produtos (S ou N): ");
      scanf(" %c", &continua);
   } while(tl <= 30 && continua == 'S');

   printf("\nPRODUTOS CADASTRADOS\n");
   for (i=0;i<tl;i++) {
      printf("\nCódigo: %d.\n", codigos[i]);
      printf("Valor: R$%0.2f.\n", precos[i]);
      printf("Quantidade em Estoque: %d.\n", estoques[i]);
   }
   for (i=1;i<tl;i++) {
      if (precos[i] > precos[indexMaisCaro])
         indexMaisCaro = i;
      if (estoques[i] > estoques[indexMaiorEstoque])
         indexMaiorEstoque = i;
   }
   printf("\nRELATÓRIO FINAL\n");
   printf("\nProduto MAIS CARO\n");
   printf("Código: %d.\n", codigos[indexMaisCaro]);
   printf("Valor: R$%0.2f.\n", precos[indexMaisCaro]);
   printf("Quantidade em Estoque: %d.\n", estoques[indexMaisCaro]);
   printf("\nProduto com MAIOR ESTOQUE\n");
   printf("Código: %d.\n", codigos[indexMaiorEstoque]);
   printf("Valor: R$%0.2f.\n", precos[indexMaiorEstoque]);
   printf("Quantidade em Estoque: %d.\n", estoques[indexMaiorEstoque]);



   return 0;
}
