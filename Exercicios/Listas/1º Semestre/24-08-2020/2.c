#include <stdio.h>

int main() {
   printf("Maior número - Leandro Ribeiro de Souza \n\n");

   float num1, num2;

   printf("Informe um número: ");
   scanf("%f", &num1);

   printf("Informe outro número: ");
   scanf("%f", &num2);

   if (num1 > num2) {
      printf("\nO número %0.2f é maior que o número %0.2f.", num1, num2);
   } else {
      if (num2 > num1) {
         printf("\nO número %0.2f é maior que o número %0.2f.", num2, num1);
      } else {
         printf("\nO número %0.2f é igual ao número %0.2f.", num2, num1);
      };
   };

   return 0;
}