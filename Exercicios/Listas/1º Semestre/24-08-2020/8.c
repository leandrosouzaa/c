#include <stdio.h>

int main() {
   printf("Cálculo de Média - Leandro Ribeiro de Souza \n\n");

   float n1,n2,n3,media;

   printf("Informe a nota 1: ");
   scanf("%f", &n1);

   printf("Informe a nota 2: ");
   scanf("%f", &n2);

   printf("Informe a nota 3: ");
   scanf("%f", &n3);

   media = (n1 + n2 + n3) / 3;

   printf("\nMédia do Aluno: %0.2f.\n", media);

   if (media < 6) {
      printf("Situação: REPROVADO");
   } else {
      printf("Situação: APROVADO");
   };

   return 0;
}
