#include <stdio.h>

int main() {
   printf("Número ao Quadrado e ao Cubo - Leandro Ribeiro de Souza \n\n");

   int i;

   for(i=1; i <=20; i++) {
      printf("%i ao quadrado é: %i.\n",i ,i * i);
      printf("%i ao cubo é: %i.\n\n",i ,i * i * i);
   }

   return 0;
}
