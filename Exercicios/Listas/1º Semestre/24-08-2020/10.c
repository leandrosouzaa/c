#include <stdio.h>

int main() {
   printf("Calculadora de Conceito - Leandro Ribeiro de Souza \n\n");

   float media, avaliacao, trabalho, simulado;

   printf("Nota do Trabalho de Laboratório: ");
   scanf("%f", &trabalho);

   printf("Nota da Avaliação Parcial: ");
   scanf("%f", &avaliacao);

   printf("Nota do Exame Final: ");
   scanf("%f", &simulado);

   media = (avaliacao * 3 + trabalho * 2 + simulado * 5)/10;

   printf("\nTrabalho de Laboratório: %0.2f.\n", trabalho);
   printf("Avaliação Parcial: %0.2f.\n", avaliacao);
   printf("Exame Final: %0.2f.\n", simulado);
   printf("Média Final: %0.2f.\n", media);

   if (media > 8 && media <= 10) {
      printf("Conceito: A.");
   } else {
      if (media > 7 && media <=8) {
         printf("Conceito: B.");
      } else {
         if (media > 5 && media <= 7) {
            printf("Conceito: C.");
         } else {
            if (media > 3 && media <= 5) {
               printf("Conceito: D.");
            } else {
               if (media >= 0 && media < 3) {
                  printf("Conceito: E.");
               } else {
                  printf("Média inválida.");
               }
            }
         }
      }
   }

   return 0;
}
