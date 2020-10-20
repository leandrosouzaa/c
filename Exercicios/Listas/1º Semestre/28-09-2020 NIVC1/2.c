#include <stdio.h>

int main() {
   printf("Subtração de Vetores - Leandro Ribeiro de Souza \n\n");

   int a[5], b[5], i;

   for (i=0; i < 5; i++) {
      printf("Informe um número para a posição %i do Vetor A: ", i);
      scanf("%i", &a[i]);
   }
   printf("\n");
   for (i=0; i < 5; i++) {
      printf("Informe um número para a posição %i do Vetor B: ", i);
      scanf("%i", &b[i]);
   }

   printf("\n\nMultiplicação entre os Vetores\n");

   for(i=0; i < 5; i++) {
      printf("\nSubtração da Posição %d dos vetores.\n", i);
      printf("%d - %d = %d\n", a[i], b[i], a[i] - b[i]);      
   }

   return 0;
}
