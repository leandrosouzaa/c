#include <stdio.h>

int main() {
   printf("Fatorial - Leandro Ribeiro de Souza \n\n");

   int i, num, total = 1;

   printf("Informe um número natural: ");
   scanf("%i", &num);

   if (num < 0) {
      printf("Não existe fatorial de número negativo.");

      return 0;
   };

   for(i = num; i > 0; i--) {
      total = i * total;
   };

   printf("\nO resultado de %i! é %i.",num, total);

   return 0;
}
