#include <stdio.h>

int main() {
   printf("Número com +1 e -1 - Leandro Ribeiro de Souza \n\n");

   float num = 0;

   printf("Informe um número: ");
   scanf("%f", &num);

   printf("\nO número %0.2f somado a 1 é %0.2f.\n", num, num + 1);
   printf("O número %0.2f subtraído 1 é %0.2f.", num, num - 1);      

   return 0;
}
