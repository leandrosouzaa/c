#include <stdio.h>

int main() {
   printf("Pares e Positivo - Leandro Ribeiro de Souza \n\n");

   int i, numeros[10], qtdPares = 0, qtdPositivos = 0;

   for (i=0; i < 10; i++) {
      printf("Informe um número para a posição %i do vetor: ", i);
      scanf("%i", &numeros[i]);

      if (numeros[i] > 0) {
         qtdPositivos++;
      }

      if (numeros[i] % 2 == 0) {
         qtdPares++;
      }
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Total de Pares: %i.\n", qtdPares);
   printf("Total de Positivos: %i\n", qtdPositivos);

   return 0;
}
