#include <stdio.h>

int main() {
   printf("Movimentação de Vetor - Leandro Ribeiro de Souza \n\n");

   int numeros[9], i, ocorrencia, qtdOcorrencias = 0;

   for (i=0; i < 9; i++) {
      printf("Informe um número para a posição %i do vetor: ", i);
      scanf("%i", &numeros[i]);

      if (numeros[i] < 0) {
         printf("Número inválido, informe novamente...\n");
         i--;
      }
   }

   for (i = 8; i >= 0; i--) {
      numeros[i] = numeros[i - 1];
   }
   numeros[0] = 0;

   printf("\nNOVO VETOR\n");
   for (i = 0; i < 9; i++) {
      printf("Posição %i: %i\n", i, numeros[i]);
   }

   printf("\nInforme um número para verificar a ocorrência dele no Vetor: ");
   scanf("%i", &ocorrencia);

   for (i = 0; i < 9; i++) {
      if (numeros[i] == ocorrencia) {
         qtdOcorrencias++;
      }
   }
   printf("Quantidade de Ocorrências do número %i no Vetor: %i.",ocorrencia, qtdOcorrencias);

   return 0;
}
