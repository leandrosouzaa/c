#include <stdio.h>

int main() {
   printf("Números entre dois números - Leandro Ribeiro de Souza \n\n");

   int i, num1, num2;

   printf("Informe um valor inteiro: ");
   scanf("%i", &num1);

   printf("Informe outro valor inteiro: ");
   scanf("%i", &num2);

   if (num1 < num2) {
      for(i=num1 + 1; i < num2; i++) {
         printf("%i\n", i);
      }
   } else {
      for(i=num2 + 1; i < num1; i++) {
         printf("%i\n", i);
      }
   }

   return 0;
}
