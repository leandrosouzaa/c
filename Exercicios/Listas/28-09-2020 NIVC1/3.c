#include <stdio.h>

int main() {
   printf("Multiplicação de um vetor - Leandro Ribeiro de Souza \n\n");

   int a[5], i, total = 1;

   for (i=0; i < 5; i++) {
      printf("Informe um número para a posição %i do Vetor (Diferente de 0): ", i);
      scanf("%i", &a[i]);

      if (a[i] != 0) {
         total*= a[i];
      } else {
         printf("Valor inválido.\n");
         i--;
      }
   }
   printf("\n");

   printf("Total da multiplicação desse vetor: %i", total);

   for(i=0; i < 5; i++) {
   }

   return 0;
}
