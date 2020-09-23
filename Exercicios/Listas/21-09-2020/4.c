#include <stdio.h>

int main() {
   printf("Média dos Alunos - Leandro Ribeiro de Souza \n\n");

   int i, notas[10], soma = 0, qtdAcima = 0;
   float media;

   for (i=0; i < 10; i++) {
      printf("Nota do Aluno %i: ", i + 1);
      scanf("%i", &notas[i]);

      soma+=notas[i];
   }

   media = soma / 10;

   for (i=0; i < 10; i++) {
      if (notas[i] > media) {
         qtdAcima++;
      }
   }

   printf("\nRELATÓRIO FINAL\n");
   printf("Soma das Notas: %i.\n", soma);
   printf("Média da Sala: %0.2f.\n", media);
   printf("Alunos acima da média: %i.", qtdAcima);

   return 0;
}
