#include <stdio.h>

int main() {
   printf("Itens de Vetor - Leandro Ribeiro de Souza \n\n");

   int nums[10], i, soma, maior;
   float media;

   for (i=0; i < 10; i++) {
      printf("Informe um número para a posição %i do Vetor: ", i);
      scanf("%i", &nums[i]);
   }

   soma = nums[0];
   maior = 0; 
   for (i=1; i < 10; i++) {
      soma+= nums[i];

      if (nums[i] > nums[maior]) {
         maior = i;
      }
   }

   media = soma / 10.0;

   printf("\nRELATÓRIO FINAL\n");
   printf("Soma do vetor: %i.\n", soma);
   printf("Média do vetor: %0.2f.\n", media);
   printf("Maior elemento: %i.\n", nums[maior]);
   printf("Posição do Maior elemento: %i.", maior);

   return 0;
}
