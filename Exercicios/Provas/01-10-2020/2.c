#include <stdio.h>

int main() {
   printf("Gabarito - Leandro Ribeiro de Souza \n\n");

   char gabarito[10], respostas[10];
   int i, qtdRasuras = 0, qtdAcertos = 0;
   float porcentagemAcertos;

   printf("GABARITO\n");
   for (i=0; i < 10; i++) {
      printf("Resposta da QUESTÃO %i: ", i + 1);
      scanf(" %c", &gabarito[i]);

      // Verifica uma entrada inválida
      if (!(gabarito[i] == 'A' || gabarito[i] == 'B' || gabarito[i] == 'C' || gabarito[i] == 'D' || gabarito[i] == 'E')) {
         printf("Alternativa inválida, informe novamente...\n");
         /*
         Se tiver uma entra inválida o i é decrementado em 1 e
         consequentemente é solicitado ao usuários informar
         novamente um valor válido para a posição.
         */
         i--;
      }
   }

   printf("\nRespostas do Candidato\n"); 
   for (i=0; i < 10; i++) {
      printf("Resposta da QUESTÃO %i: ", i + 1);
      scanf(" %c", &respostas[i]);

      if (!(respostas[i] == 'A' || respostas[i] == 'B' || respostas[i] == 'C' || respostas[i] == 'D' || respostas[i] == 'E' || respostas[i] == 'X')) {
         /*
         Se tiver uma entra inválida o i é decrementado em 1 e
         consequentemente é solicitado ao usuários informar
         novamente um valor válido para a posição.
         */
         printf("Alternativa inválida, informe novamente...\n");
         i--;
      }
   }

   for (i=0; i < 10; i++) {
      if (respostas[i] == 'X') {
         qtdRasuras++;
      }

      if (respostas[i] == gabarito[i]) {
         qtdAcertos++;
      }
   }

   porcentagemAcertos = qtdAcertos * 10;

   printf("\nRELATÓRIO FINAL\n");
   printf("Quantidade de Acertos: %i.\n", qtdAcertos);
   printf("Porcentagem de Acertos: %0.2f%%.\n", porcentagemAcertos);
   printf("Quantidade de Rasuras: %i.\n", qtdRasuras);

   return 0;
}
