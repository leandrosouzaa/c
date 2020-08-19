#include <stdio.h>

int main() {
   printf("Batidas do Coração - Leandro Ribeiro de Souza \n\n");

   int idade = 0;
   float totalBatidas = 0;

   printf("Informe a idade: ");
   scanf("%i", &idade);

   totalBatidas = idade * 365.25 * 24 * 60 * 60;

   printf("\nIdade: %i.", idade);
   printf("Total de Batidas: %f.", totalBatidas); 

   return 0;
}
