#include <stdio.h>

int main() {
   printf("Cálculo de Média - Leandro Ribeiro de Souza \n\n");

   float notas[3], media;
   int i;

   for (i=0; i<3; i++) {
      printf("Informe a nota %i :", i + 1);
      scanf("%f", &notas[i]);
      if (notas[i] < 0 || notas[i] > 10) {
         printf("\nNota inválida, finalizando Programa.");
         return 0;
      }
   }

   for (i--; i>=0; i--) {
      media = media + notas[i]/3;
   };

   printf("\nMédia do Aluno: %0.2f.\n", media);

   if (media < 6) {
      printf("Situação: REPROVADO");
   } else {
      printf("Situação: APROVADO");
   };

   return 0;
}

