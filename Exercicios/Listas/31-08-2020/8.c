#include <stdio.h>

int main() {
   printf("Média da Sala - Leandro Ribeiro de Souza \n\n");

   int i, aprovados = 0, reprovados = 0;
   float media, total = 0, mediaGlobal, percentualAprovados;

   for (i=1; i <= 10; i++) {
      printf("Informe a Média do Aluno %i: ", i);
      scanf("%f", &media);

      if (media < 0 || media > 10) {
         printf("Média inválida, finalizando o programa...");

         return 0;
      };

      total = total + media;
      if (media < 6) {
         reprovados++;
      } else {
         aprovados++;
      };
   };

   mediaGlobal = total / 10;
   percentualAprovados = 10 * aprovados;

   printf("\nMédia Global da sala: %0.2f\n", mediaGlobal);
   printf("\nAlunos aprovados: %i\n", aprovados);
   printf("Percentual de alunos aprovados: %0.2f%%\n", percentualAprovados);
   printf("\nAlunos reprovados: %i\n", reprovados);
   printf("Percentual de alunos reprovados: %0.2f%%\n", 100 - percentualAprovados);

   return 0;
}
