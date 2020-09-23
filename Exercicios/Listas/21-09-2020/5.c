#include <stdio.h>

int main() {
   printf("Vetor de Números - Leandro Ribeiro de Souza \n\n");

   int i, nums[10], soma = 0, maiorI = 0;

   for (i=0; i < 10; i++) {
      printf("Informe um número para a posição %i do: ", i);
      scanf("%i", &nums[i]);
   }

   maiorI = 0; soma = nums[0];

   for (i=1; i < 10; i++) {
      if (nums[i] > nums[maiorI]) {
         maiorI = i;
      };
      soma+= nums[i];
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Maior Elemento: %i.\n", nums[maiorI]);
   printf("Posição do maior Elemento: %i.\n", maiorI);
   printf("Soma dos Elementos: %i.\n", soma);

   return 0;
}
