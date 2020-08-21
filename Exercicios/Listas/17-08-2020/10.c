#include <stdio.h>

int main() {
   printf("Média Bimestral - Leandro Ribeiro de Souza \n\n");

   float media, avaliacao, trabalho, simulado = 0;

   printf("Nota da Avaliação Bimestral: ");
   scanf("%f", &avaliacao);

   printf("Nota do Trabalho Prático: ");
   scanf("%f", &trabalho);

   printf("Nota do Simulado: ");
   scanf("%f", &simulado);

   media = (avaliacao * 6 + trabalho * 2 + simulado * 2)/10;

   printf("\nAvaliação Bimestral: %0.2f.\n", avaliacao);
   printf("Trabalho Prático: %0.2f.\n", trabalho);
   printf("Simulado: %0.2f.\n", simulado);
   printf("Média Final: %0.2f.", media);

   return 0;
}
