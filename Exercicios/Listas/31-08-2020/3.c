#include <stdio.h>

int main() {
   printf("Tabuada - Leandro Ribeiro de Souza \n\n");

   int i, num;

   printf("Informe um número inteiro: ");
   scanf("%i", &num);

   printf("\nTABUADA DO  %i\n\n", num);

   for(i=0; i <=10; i++) {
      printf("%i x %i: %i\n", num, i, num * i);
   };

   return 0;
}
