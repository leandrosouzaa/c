#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   printf("Busca no Vetor - Leandro Ribeiro de Souza \n\n");
   srand(time(NULL));

   int vetor[12], i, a, b;

   printf("Preencha o vetor:\n");
   for(i=0; i < 12; i++) {
      printf("Vetor[%d]: ", i);

      vetor[i] = rand() % 20;
      printf("%d.\n", vetor[i]);

      // scanf("%d", &vetor[i]);
   }

   printf("\n\nInforme uma posição do vetor: ");
   scanf("%d", &a);

   printf("Informe uma outra posição do vetor: ");
   scanf("%d", &b);

   if(a > 11 || b > 11 ) {
      printf("Valores inválido. Reinicie o programa.\n");
   } else {
      printf("%d + %d = %d", vetor[a], vetor[b], vetor[a]+vetor[b]);
   }


   return 0;
}