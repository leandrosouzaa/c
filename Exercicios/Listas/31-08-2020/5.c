#include <stdio.h>

int main() {
   printf("Quantidade de Números - Leandro Ribeiro de Souza \n\n");

   int i, qtdNums = 0, qtdNumsPositivos = 0, qtdNulos = 0;
   float num;

   printf("Informe a quantidade de números que deseja informar: ");
   scanf("%i", &i);

   for(i; i > 0; i--) {
      printf("Informe um número: ");
      scanf("%f", &num);
      qtdNums++;
      if (num > 0) {
         qtdNumsPositivos++;
      } else {
         if (num == 0) {
            qtdNulos++;
         };
      };
   };

   printf("\nTotal de números informados: %i.\n", qtdNums);
   printf("Total de números positivos: %i.\n", qtdNumsPositivos);
   printf("Total de números negativos: %i.\n", qtdNums - qtdNumsPositivos - qtdNulos);
   printf("Total de números nulos: %i.\n", qtdNums - qtdNumsPositivos - qtdNulos);
   
   return 0;
}
