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

int main() {
   printf("Localiza posição - Leandro Ribeiro de Souza \n\n");
   srand(time(NULL));

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

   printf("Valor encontrado na posição %d (-1 = inexistente).\n", busca_posicao(vetor, valor));
   return 0;
}