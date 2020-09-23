#include <stdio.h>

int main() {
   printf("Vetor de Números - Leandro Ribeiro de Souza \n\n");

   float nums[5], soma = 0, media, maior, menor;
   int i;

   //Loop para leitura
   for (i=0; i < 5; i++) {
      printf("%i: Informe um número: ", i + 1);
      scanf("%f", &nums[i]);
   }

   maior = nums[0]; menor = nums[0]; soma = nums[0];

   //Loop para Calculo
   for (i=1; i < 5; i++) {
      if (nums[i] > maior) {
         maior = nums[1];
      };

      if (nums[i] < menor) {
         maior= nums[1];
      }

      soma+= nums[1];
   }

   media = soma / 5;

   printf("\nRELATÓRIO FINAL\n");
   printf("Maior Elemento: %0.2f.\n", maior);
   printf("Menor Elemento: %0.2f.\n", menor);
   printf("Soma dos Elementos: %0.2f.\n", soma);
   printf("Média dos Elementos: %0.2f.\n", media);

   return 0;
}
