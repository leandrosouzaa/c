#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca_posicao(int vetor[10], int valor) {
   int i;
   for(i=0; i < 10; i++) {
      if(vetor[i]==valor)
         return i;
   }

   return -1;
}

void exclui_posicao(int vetor[10], int posicao) {
   int i;

   for(i=posicao; i < 9; i++) {
      vetor[i] = vetor[i+1];
   }
   vetor[9] = 0;
}

void apresenta_vetor(int vetor[16]) {
   int i;

   for(i=0; i < 10; i++) {
      printf("\nVetor[%d]: %d.", i, vetor[i]);
   }
}

int main() {
   printf("Exclui do Vetor - Leandro Ribeiro de Souza \n\n");

   int vetor[10], i, valor;

   printf("Preencha o vetor:\n");
   for(i=0; i < 10; i++) {
      printf("Vetor[%d]: ", i);

      vetor[i] = rand() % 20;
      printf("%d.\n", vetor[i]);

      // scanf("%d", &vetor[i]);
   }

   printf("Informe um valor para busca: ");
   scanf("%d", &valor);

   int posicao = busca_posicao(vetor, valor);

   if(posicao == -1) {
      printf("\nNão encontrado.\n");
   } else {
      printf("Excluindo a posição %d do vetor.", posicao);
      exclui_posicao(vetor, posicao);
      printf("\nNovo vetor:\n");
      apresenta_vetor(vetor);
   }

   return 0;
}