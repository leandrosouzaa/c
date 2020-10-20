#include <stdio.h>

int main() {
   printf("Maio número (Troca de Valores) - Leandro Ribeiro de Souza \n\n");

   float a,b, temp;

   printf("Informe um valor para A: ");
   scanf("%f", &a);

   printf("Informe um valor para B: ");
   scanf("%f", &b);

   if (a > b) {
      printf("\nO número %0.2f(A) é maior que o número %0.2f(B).\n", a, b);
   } else {
      if (b > a) {
         printf("\nO número %0.2f(B) é maior que o número %0.2f(A).\n", b, a);
         temp = a;
         a = b;
         b = temp;
      } else {
         printf("\nO número %0.2f(A) é igual ao número %0.2f(B).\n", a, b);
      };
   };

   printf("Valor de A: %0.2f.\n", a);
   printf("Valor de B: %0.2f.", b);

   return 0;
}
