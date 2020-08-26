#include <stdio.h>

int main() {
   printf("Números Pares - Leandro Ribeiro de Souza \n\n");

   int num = 0;

   printf("Informe um número inteiro: ");
   scanf("%i", &num);

   if (num % 2 == 0) {
      printf("\nO número %i é par.", num);
   } else {
      printf("O número %i é ímpar.", num);
   }

   return 0;
}