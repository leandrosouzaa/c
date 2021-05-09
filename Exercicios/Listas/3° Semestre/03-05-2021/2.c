#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Alocação Dinâmica - Leandro Ribeiro de Souza \n\n");

   int *vetor, size;
   
   printf("Informe a quantidade de elementos que deseja: ");
   scanf("%d", &size);

   vetor = (int *) malloc(size * sizeof(int));

   if(vetor == NULL) {
      printf("\nERRO: Memória insuficiente.\n");
   }

   for(int i=0; i<size; i++) {
      vetor[i] = i+1;
   }

   for(int i=0; i<size; i++) {
      printf("%d ", vetor[i]);
   };
   free(vetor);

   return 0;
}