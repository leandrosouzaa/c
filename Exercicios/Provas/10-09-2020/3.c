#include <stdio.h>

int main() {
   printf("Nivelamento - Leandro Ribeiro de Souza \n\n");

   float diag, av1, av2, av3 ,media;

   printf("Informe a nota do Aluno na Diagnóstica: ");
   scanf("%f", &diag);

   printf("Informe a nota da Atividade Avaliativa 1: ");
   scanf("%f", &av1);

   printf("Informe a nota da Atividade Avaliativa 2: ");
   scanf("%f", &av2);

   printf("Informe a nota da Atividade Avaliativa 3: ");
   scanf("%f", &av3);

   printf("\nRELATÓRIO FINAL\n");

   if (diag < 5 || av1 < 5 || ((av1+av2) / 2 < 5)) {
      printf("Situação do Nivelamento: CONVOCADO");   
      media = (av1 + av2 + av3) / 3 + 1;
   } else {
      printf("Situação do Nivelamento: DISPENSADO");
      media = (av1 + av2 + av3) / 3;
   }

   printf("\nMédia Final: %0.2f", media);

   return 0;
}
