#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca_posicao(int vetor[12], int valor) {
   int i;
   
   for(i=0; i < 12; i++) {
      if(vetor[i] == valor)
         return i;
   }

   return -1;
}

int main() {
   printf("Busca no Vetor - Leandro Ribeiro de Souza \n\n");
   srand(time(NULL));

   int vetor[12], i, temp, posicao;

   printf("Preencha o vetor:\n");
   for(i=0; i < 12; i++) {
      printf("\nVetor[%d]: ", i);

      vetor[i] = rand() % 20;
      printf("%d.", vetor[i]);

      // scanf("%d", vetor[i]);
   }

   printf("\n\nInforme um valor para busca: ");
   scanf("%d", &temp);
   posicao = busca_posicao(vetor, temp);
   printf("Valor encontrado na posição %d%s\n", posicao, posicao == -1 ? " (Inexistente)." : ".");

   printf("\nInforme um outro valor para busca: ");
   scanf("%d", &temp);
   posicao = busca_posicao(vetor, temp);
   printf("Valor encontrado na posição %d%s\n", posicao, posicao == -1 ? " (Inexistente)." : ".");


   return 0;
}