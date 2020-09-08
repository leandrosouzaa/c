#include <stdio.h>

int main() {
   printf("Média da Sala - Leandro Ribeiro de Souza \n\n");

   int i, aprovados = 0, reprovados = 0;
   float n1, n2, media, total = 0, mediaGlobal, percentualAprovados;

   for (i=1; i <= 10; i++) {
      printf("\nMÉDIAS DO ALUNO %i.\n", i);

      printf("Informe a média do Primeiro Bimestre: ");
      scanf("%f", &n1);
      printf("Informe a média do Segundo Bimestre: ");
      scanf("%f", &n2);

      media = (n1+n2) / 2;

      total = total + media;
      if (media < 6) {
         reprovados++;
      } else {
         aprovados++;
      }
   }

   mediaGlobal = total / 10;
   percentualAprovados = 10 * aprovados;

   printf("\n\nMédia Global da sala: %0.2f\n", mediaGlobal);
   printf("\nAlunos aprovados: %i\n", aprovados);
   printf("Percentual de alunos aprovados: %0.2f%%\n", percentualAprovados);
   printf("\nAlunos reprovados: %i\n", reprovados);
   printf("Percentual de alunos reprovados: %0.2f%%\n", 100 - percentualAprovados);

   return 0;
}
