#include <stdio.h>

int main() {
   printf("Número ao Quadrado - Leandro Ribeiro de Souza \n\n");

   float num, quadrado = 0;

   printf("Informe um número: ");
   scanf("%f", &num);

   quadrado = num * num;

   printf("\nO número %0.2f ao quadrado é %0.2f.", num, quadrado);      

   return 0;
}
