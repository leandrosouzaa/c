#include <stdio.h>

int main() {
   printf("10 números - Leandro Ribeiro de Souza \n\n");

   int i;
   float num, menorValor, maiorValor, total, media;


   printf("Informe um número: ");
   scanf("%f", &num);

   menorValor = num;
   maiorValor = num;
   total = num;

   for (i=1; i < 10; i++) {
      printf("Informe outro número: ");
      scanf("%f", &num);

      if (num < menorValor) {
         menorValor = num;
      } else {
         if (num > maiorValor) {
            maiorValor = num;
         }
      }

      total = total + num;
   }

   media = total / 10;

   printf("\nTotal de números digitados: 10.\n");
   printf("Total dos números digitados: %0.2f.\n", total);
   printf("Menor número digitado: %0.2f.\n", menorValor);
   printf("Maior número digitado: %0.2f.\n", maiorValor);
   printf("Média dos valores digitados: %0.2f.\n", media);

   return 0;
}
