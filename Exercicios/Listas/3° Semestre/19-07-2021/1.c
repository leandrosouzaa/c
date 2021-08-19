#include <stdio.h>

int somaDigitos(int num) {
   if(num < 10) {
      return num;
   }

   return somaDigitos(num/10) + num % 10;
}

int main() {
   printf("Soma de Digitos - Leandro Ribeiro de Souza \n\n");

   int temp;
   do {
      printf("\nDigite um numero: ");
      scanf("%d", &temp);
      printf("Soma dos Algarismos: %d.\n", somaDigitos(temp));
   } while (temp >= 0);

   return 0;
}