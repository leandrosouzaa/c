#include <stdio.h>

int main() {
   printf("Quitanda do João - Leandro Ribeiro de Souza \n");
   
   int temp, compra[20][10] = {0}, i = 0, j, quantidade[15] = {0}, indexCliente, somaCliente = 0, indexProdutoMaisComprado = 0;
   char condicao;

   do {
      j=0;
      do {
         printf("\nITEM: %d | CLIENTE: %d\n", j + 1, i + 1);
         do {
            printf("Código do Produto (-1 para finalizar): ");
            scanf("%d", &temp);
         } while(!(temp < 16));
         if (temp > 0) {
            compra[i][j] = temp;
         }
         j++;
      } while(j < 10 && temp > 0);
      i++;
      printf("\nExistem mais clientes (S/N):");
      scanf(" %c", &condicao);
   } while((condicao == 'S'|| condicao == 's') && i < 20);

   for(i=0; i < 20; i++) {
      temp = 0;
      for(j=0; j < 10; j++) {
         if (compra[i][j] != 0) {
            temp++; 
            quantidade[compra[i][j] - 1]++;
         }
      }
      if (temp > somaCliente) {
         indexCliente = i;
      }
   }

   printf("\nRELATÓRIO INDIVIDUAL\n");
   for(i=0; i < 15; i++) {
      if (quantidade[i] > quantidade[indexProdutoMaisComprado]) {
         indexProdutoMaisComprado = i;
      }
      printf("\nCódigo: %d.\n", i + 1);
      printf("Quantidade Vendida: %d.\n", quantidade[i]);
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Cliente que mais comprou: %d.\n", indexCliente + 1);
   printf("Código do Produto mais Comprado: %d.\n", indexProdutoMaisComprado + 1);

   return 0;
}
