#include <stdio.h>

int main() {
   printf("0 à 30 - Leandro Ribeiro de Souza \n\n");

   int i;

   for(i=0; i<=30; i+=2) {
      printf("%i\n", i);
   }

   for(i=29; i > 0; i--) {
      printf("%i\n", i);
   }

   return 0;
}