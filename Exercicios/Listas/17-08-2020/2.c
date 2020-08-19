#include <stdio.h>

int main() {
   printf("Calculadora de Dias - Leandro Ribeiro de Souza \n\n");

   int dia, mes, diasPassados = 0;

   printf("Informe um Dia: ");
   scanf("%i.", &dia);

   printf("Informe um Mês: ");
   scanf("%i.", &mes);

   diasPassados = dia + ((mes - 1) * 30);

   printf("\nJá se passaram %i dias desde o início do ano até o dia %i/%i!", diasPassados, dia, mes);

   return 0;
}
