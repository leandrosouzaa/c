#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca_posicoes(int vetor[16]) {
   int i, temp;

   for(i=0; i < 8; i++) {
      temp = vetor[i];
      vetor[i] = vetor[i+8];
      vetor[i+8] = temp; 
   }
}

void apresenta_vetor(int vetor[16]) {
   int i;

   for(i=0; i < 16; i++) {
      printf("\nVetor[%d]: %d.\n", i, vetor[i]);
   }

}

int main() {
   printf("Troca posições - Leandro Ribeiro de Souza \n\n");
   srand(time(NULL));

   int vetor[16], i;

   printf("Preencha o vetor:\n");
   for(i=0; i < 16; i++) {
      printf("Vetor[%d]: ", i);

      // vetor[i] = rand() % 20;
      // printf("%d.", vetor[i]);

      scanf("%d", &vetor[i]);
   }

   troca_posicoes(vetor);

   printf("\nVetor trocado:\n");
   apresenta_vetor(vetor);


   return 0;
}