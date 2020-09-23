#include <stdio.h>

int main() {
   printf("Menu - Leandro Ribeiro de Souza \n\n");

   int item, i, num, total = 1, produtoPares = 1 , produtoImpares = 1;

   do {
      printf("\nSELECIONE UMA OPÇÃO:\n");
      printf("1 - Números divididor por 7 com resto 6 (5000 - 6000) \n");
      printf("2 - Fatorial.\n");
      printf("3 - Produto de Pares e Ímpares\n");
      printf("4 - Encerrar Programa.\n");
      printf("Opção: ");
      scanf("%i", &item);
      
      switch (item)
      {
      case 1:
         printf("\nNÚMEROS DIVIDIDOS POR 7 COM RESTO 6 (5000 - 6000)\n");
         
         for (i=5000; i <= 6000; i++) {
               printf("%i, ", i);
            }
         break;
      case 2:
         printf("\nFATORIAL DE UM NÚMERO\n");

         printf("Informe um número natural: ");
         scanf("%i", &num);
      
         if (num < 0) {
            printf("Não existe fatorial de número negativo.");
            printf("Voltando ao Menu...\n");
            break;
         }
      
         for(i = num; i > 0; i--) {
            total = i * total;
            printf("%i", i);
         }

         printf("\nO resultado de %i! é %i.\n",num, total);

         break;

      case 3:
         printf("\nPRODUTO DE PARES E ÍMPARES\n");

         produtoImpares = 1; produtoPares = 1;

         printf("Informe um número natural maior que 1: ");
         scanf("%i", &num);
 
         if (num < 0) {
            printf("Número inválido.");
            printf("Voltando ao Menu...\n");
            break;
         }

         for (i = num; i > 1; i--) {
            if (i % 2 == 0) {
               produtoPares = i * produtoPares * 1;
            } else {
               produtoImpares = i * produtoImpares * 1;
            }
         }

         printf("\nRELATÓRIO FINAL\n");
         printf("Produto dos Números Pares: %i.\n", produtoPares);
         printf("Produto dos Números Ímpares: %i.\n", produtoImpares);

         break;

      default:
         printf("\nEntrada inválida...\n");
         printf("Voltando para o Menu...\n");
         break;
      }
   } while (item != 4);

   return 0;
}
